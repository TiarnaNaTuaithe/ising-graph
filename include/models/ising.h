#pragma once
/**
@file
@brief Implementation of the Ising Model
*/

#include <numeric>
#include <vector>
#include "algorithms/ising/all.h"
#include "graph/all.h"
#include "initialisers/ising/all.h"

namespace isinggraph::ising {

//! An Ising model implementation with generic graph, algorithm and initialiser
template <class AlgorithmPolicy, class GraphPolicy,
	  class InitialiserPolicy = Random>
class Ising {
 public:
  using site_type_t = typename AlgorithmPolicy::site_type_t;

  // We do it this way because we can't initialise the spins if we inherit and
  // use the graph's constructors only. Unfortunately, this means brace-enclosed
  // initialiser lists are disallowed. This could be looked at in future.

  //! This constructor covers all the possible graph constructors
  template <typename... Args>
  Ising(Args&&... args) : graph_{std::forward<Args>(args)...} {
    spins_.resize(graph_.size());
    init_.initialise(spins_);
  }

  //! The other constructor can't capture initialiser lists, so we do that here
  Ising(std::initializer_list<std::vector<site_type_t>> init_list)
      : graph_{init_list} {
    spins_.resize(graph_.size());
    init_.initialise(spins_);
  }

  //! Update all of the spins
  void update(double const& beta) {
    algo_.sweep(spins_, beta, [&](int n) { return graph_.neighbours(n); });
  }

  std::vector<site_type_t> const & spins() {
    return spins_;
  }

  //! Get the average magnetisation of the lattice
  double average_magnetisation() const {
    auto magnetisation = std::accumulate(spins_.begin(), spins_.end(), 0);
    return static_cast<double>(magnetisation) / spins_.size();
  }

  //! Get the susceptibility of the lattice
  double susceptibility() const {
    auto const m = average_magnetisation();
    return m * m;
  }

 private:
  GraphPolicy graph_;
  AlgorithmPolicy algo_;
  InitialiserPolicy init_;
  std::vector<site_type_t> spins_;
};

}  // namespace ising
