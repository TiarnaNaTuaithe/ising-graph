#pragma once
/**
@file
@brief This file contains a random initialiser for the Ising model
*/

#include <random>
#include <vector>
#include "../../mersenne.h"

namespace isinggraph {
namespace ising {

//! An initialiser for the Ising model that sets spins to random values
class Random {
 public:
  //! The initialiser function
  void initialise(std::vector<int>& spins) {
    for (auto& s : spins) {
      s = 2 * random_int_(random::mersenne_twister()) - 1;
    }
  }

 private:
  std::uniform_int_distribution<int> random_int_{0, 1};
};

}  // namespace ising
}  // namespace isinggraph
