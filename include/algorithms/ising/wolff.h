#pragma once
/**
@file
@brief This file contains a Wolff cluster algorithm implementation for the Ising
model
*/

#include <queue>
#include <vector>
#include "../../mersenne.h"

namespace isinggraph::ising {

//! A Wolff algorithm policy for the Ising model
class Wolff {
 public:
  using site_type_t = int;

  //! Performs a Wolff cluster update
  /*!
    Performs a Wolff clsuter update
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
void Wolff::sweep(std::vector<site_type_t>& values, double const& beta,
                  F&& get_neighbours) {
  auto const cluster_probability = 1.0 - exp(-2 * beta);
  auto initial_site =
      random_double_(random::mersenne_twister()) * values.size();
  auto const spin = values[initial_site];
  std::vector<bool> in_cluster(values.size(), false);

  std::queue<int> cluster;
  cluster.push(initial_site);
  in_cluster[initial_site] = true;

  while (!cluster.empty()) {
    for (auto const& n : get_neighbours(cluster.front())) {
      if (!in_cluster[n] && values[n] == spin &&
          cluster_probability > random_double_(random::mersenne_twister())) {
        cluster.push(n);
        in_cluster[n] = true;
      }
    }
    cluster.pop();
  }

  for (auto i = 0u; i < values.size(); ++i) {
    if (in_cluster[i]) {
      values[i] *= -1;
    }
  }
}

}  // namespace isinggraph::ising
