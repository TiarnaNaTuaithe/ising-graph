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
    " -a, --average-over \n\t number of individual measurements to average "
    "over for each output measurment\n"
    " -g, --grid-size \n\t side length of the square grid\n";

using isinggraph::Grid2D;
using isinggraph::ising::Ising;
using isinggraph::ising::Metropolis;

int main(int argc, char** argv) {
  double beta_low = 0.1;
  double beta_high = 1.0;
  int measurements = 10;
  int thermalisation_steps = 10;
  int average_over = 10;
  int grid_size = 50;

  char opt;
  int index;
  while ((opt = getopt_long(argc, argv, "hs:e:m:t:a:g:", longopts, &index)) !=
         -1) {
    switch (opt) {
      case 'h':
        std::cout << usage << '\n';
        exit(0);
        break;
      case 's':
        beta_low = atof(optarg);
        break;
      case 'e':
        beta_high = atof(optarg);
        break;
      case 'm':
        measurements = atoi(optarg);
        break;
      case 't':
        thermalisation_steps = atoi(optarg);
        break;
      case 'a':
        average_over = atoi(optarg);
        break;
      case 'g':
        grid_size = atoi(optarg);
        break;
      default:
        std::cerr << "Error: invalid option.\n";
        std::cerr << usage << '\n';
        exit(1);
    }
  }

  Ising<Metropolis, Grid2D> ising_grid(grid_size);
  auto results = isinggraph::measure_susceptibility(
      ising_grid, beta_low, beta_high, measurements, thermalisation_steps,
      average_over);

  for (auto [beta, susceptibility] : results) {
    std::cout << beta << '\t' << susceptibility << '\n';
  }
}
