#pragma once
/**
@file
@brief This file contains a weight policy with a constant weight of one
*/

#include "base.h"

namespace isinggraph {
namespace graph {
namespace weight {

//! A weight policy that gives a constant weight of one to all edges
class None : public Weight<int> {
 public:
  int weight(int, int) override {
    return 1;
  }
};

}  // namespace weight
}  // namespace graph
}  // namespace isinggraph
