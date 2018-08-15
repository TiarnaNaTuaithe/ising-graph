#include "models/ising.h"
#include "gtest/gtest.h"

TEST(IsingTest, Instantiation) {
  using namespace isinggraph::ising;

  Ising<Metropolis, isinggraph::Graph> ising_graph({{1, 2}, {0, 2}});
  Ising<Metropolis, isinggraph::Grid2D> ising_grid(10);
}
