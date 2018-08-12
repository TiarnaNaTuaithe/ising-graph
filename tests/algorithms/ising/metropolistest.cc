#include "algorithms/ising/metropolis.h"
#include <vector>
#include "gtest/gtest.h"

TEST(MetropolisTest, ObviousFlip) {
  isinggraph::ising::algorithm::Metropolis m;
  std::vector<std::vector<int>> const neighbours{
      {3, 1}, {0, 2}, {1, 3}, {2, 0}};

  std::vector<int> spins{1, -1, 1, -1};
  m.sweep(spins, 1.0, [&](int n) { return neighbours[n]; });
  // The first spin should be guaranteed to have flipped.
  EXPECT_EQ(-1, spins[0]);

  std::vector<int> opposite_spins{-1, 1, -1, 1};
  m.sweep(opposite_spins, 1.0, [&](int n) { return neighbours[n]; });
  // The first spin should be guaranteed to have flipped.
  EXPECT_EQ(1, opposite_spins[0]);
}
