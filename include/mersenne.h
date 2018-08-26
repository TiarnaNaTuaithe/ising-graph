#pragma once
/**
@file
@brief This file seeds a mersenne twister object, used to generate random
numbers
*/

#include <random>

namespace isinggraph::random {

//! A mersenne twister engine with which to generate random numbers
inline std::mt19937& mersenne_twister() noexcept {
  static std::mt19937 mt{9876789};
  return mt;
}

}  // namespace isinggraph::random
