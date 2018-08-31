/**
@file
@brief A main to record susceptibilities with different models.
*/

#include <getopt.h>
#include <iostream>
#include <vector>
#include "measurement/susceptibility.h"
#include "models/ising.h"

static constexpr struct option longopts[] = {
    {"help", 0, nullptr, 'h'},
    {"beta-start", 1, nullptr, 's'},
    {"beta-end", 1, nullptr, 'e'},
    {"measurements", 1, nullptr, 'm'},
    {"thermalisation-steps", 1, nullptr, 't'},
    {"average-over", 1, nullptr, 'a'},
    {"grid-size", 1, nullptr, 'g'},
    {nullptr, 0, nullptr, 0},
};

static constexpr auto usage =
    " Usage:\n"
    " -h, --help \n\t prints this message\n"
    " -s, --beta-start \n\t start of beta range\n"
    " -e, --beta-end \n\t end of beta range\n"
    " -m, --measurements \n\t number of measurements to take\n"
    " -t, --thermalisation-steps \n\t number of thermalisations between each "
    "measured update\n"
    " -o, --average-over \n\t number of individual measurements to average "
    "over for each output measurment\n"
    " -g, --grid-size \n\t side length of the square grid\n"
    "-a, --algorithm \n\t 1 for Metropolis, 2 for Wolff cluster";

using isinggraph::Grid2D;
using isinggraph::Ising;
using isinggraph::ising::Metropolis;
using isinggraph::ising::Wolff;

struct Args {
  double beta_low = 0.1;
  double beta_high = 1.0;
  int measurements = 10;
  int thermalisation_steps = 10;
  int average_over = 10;
  int grid_size = 50;
};

template <typename Model>
void measure(Model& ising, Args const& a) {
  auto results = isinggraph::measure_susceptibility(
      ising, a.beta_low, a.beta_high, a.measurements, a.thermalisation_steps,
      a.average_over);
  for (auto [beta, susceptibility] : results) {
    std::cout << beta << '\t' << susceptibility << '\n';
  }
}

int main(int argc, char** argv) {
  Args args;
  int algorithm = 0;
  int index;
  char opt;
  while ((opt = getopt_long(argc, argv, "hs:e:m:t:o:g:a:", longopts, &index)) !=
         -1) {
    switch (opt) {
      case 'h':
        std::cout << usage << '\n';
        exit(0);
        break;
      case 's':
        args.beta_low = atof(optarg);
        break;
      case 'e':
        args.beta_high = atof(optarg);
        break;
      case 'm':
        args.measurements = atoi(optarg);
        break;
      case 't':
        args.thermalisation_steps = atoi(optarg);
        break;
      case 'o':
        args.average_over = atoi(optarg);
        break;
      case 'g':
        args.grid_size = atoi(optarg);
        break;
      case 'a':
        algorithm = atoi(optarg);
        break;
      default:
        std::cerr << "Error: invalid option.\n";
        std::cerr << usage << '\n';
        exit(1);
    }
  }

  switch (algorithm) {
    case 1: {
      Ising<Metropolis, Grid2D> ising_grid(args.grid_size);
      measure(ising_grid, args);
      break;
    }
    case 2: {
      Ising<Wolff, Grid2D> ising_grid(args.grid_size);
      measure(ising_grid, args);
      break;
    }
    default:
      std::cerr << "Invalid input for algorithm.\n";
      std::cerr << usage << '\n';
      exit(1);
  }
}
