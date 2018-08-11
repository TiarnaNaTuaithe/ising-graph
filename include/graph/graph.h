#pragma once
/**
@file
@brief This file contains a simple graph implementation
 */

#include <vector>
#include "weight_policies.h"

namespace isinggraph {
namespace graph {

//! A graph with edge weights decided by a WeightPolicy
template <typename WeightPolicy>
class Graph {
  std::vector<std::vector<int>> neighbours_;
  WeightPolicy weights_;

 public:
  using weight_t = typename WeightPolicy::weight_t;

  //! A constuctor from a neighbour vector
  Graph(std::vector<std::vector<int>> n) : neighbours_{n} {
  }

  //! Get the neighbours of a given node
  std::vector<int> const& neighbours(int node) {
    return neighbours_[node];
  }

  //! Get the weights of the neighbour connections of a given node
  weight_t weight(int node, int neighbour) {
    return weights_.weight(node, neighbour);
  }

  //! Get the degree of a given node
  int degree(int n) {
    return neighbours_[n].size();
  }

  //! Get the number of nodes in the graph
  int size() {
    return neighbours_.size();
  }
};

}  // namespace graph
}  // namespace isinggraph
