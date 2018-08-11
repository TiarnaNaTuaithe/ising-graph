#pragma once
/**
@file
@brief This file contains the weight policy base class
*/

namespace isinggraph {
namespace graph {
namespace weight {

//! Base class for the weight policies used by Graph
template <typename T>
class Weight {
 public:
  using weight_t = T;

  //! Get the weight of the connection from a node to one of its neighbours
  /*!
    @param node The index of the node we're interested in
    @param neighbour_index The index of the neighbour in the neighbour vector of
    node
    @return The weight of the edge between node and neighbour
  */
  virtual weight_t weight(int node, int neighbour_index) = 0;
  virtual ~Weight(){};
};

}  // namespace weight
}  // namespace graph
}  // namespace isinggraph
