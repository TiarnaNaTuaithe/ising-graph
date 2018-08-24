#pragma once
/**
@file
@brief This file contains a Metropolis algorithm implementation for the Ising
model
*/

#include <stdexcept>
#include <vector>
#include "../../mersenne.h"

namespace isinggraph::ising {

//! A Metropolis algorithm policy for the Ising model
class Metropolis {
 public:
  using site_type_t = int;

  //! Performs a metropolis update for each node
  /*!
    Sweeps the entire graph and performs a Metropolis update of each node
    @param values The vector of node values
    @param beta The inverse temperature parameter of the system
    @param get_neighbours A callback to get a vector of the neighbours of a node
   */
  template <typename F>
  void sweep(std::vector<site_type_t>& values, double const& beta,
             F&& get_neighbours);

 private:
  std::uniform_real_distribution<double> random_double_{
      0.0, 1.0};  //! < Generates random doubles in [0,1)
};

template <typename F>
void Metropolis::sweep(std::vector<site_type_t>& values, double const& beta,
                       F&& get_neighbours) {
  auto energy_difference = [&](int node) {
    int mismatched_neighbours = 0;
    auto const& neighbours = get_neighbours(node);
    for (auto const& n : neighbours) {
      mismatched_neighbours += static_cast<int>(values[n] != values[node]);
    }
    // The following is derived from the Ising Hamiltonian.
    return static_cast<int>(2 *
                            (neighbours.size() - 2 * mismatched_neighbours));
  };

  for (auto& node : values) {
    auto const delta_e = energy_difference(node);
    if (delta_e < 0 ||
        exp(-1 * beta * delta_e) > random_double_(random::mersenne_twister())) {
      node *= -1;
    }
  }
}

}  // namespace isinggraph::ising
