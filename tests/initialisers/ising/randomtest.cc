#include "initialisers/ising/random.h"
#include "gtest/gtest.h"

TEST(InitialiserTest, Randomiser) {
  std::vector<int> values(1000, 0);

  ::isinggraph::ising::initialiser::Random r;
  r.initialise(values);

  int count_up = 0;
  int count_down = 0;
  for (auto const& v : values) {
    EXPECT_TRUE(v == 1 || v == -1);
    if (v == 1) {
      ++count_up;
    } else {
      ++count_down;
    }
  }

  // This can fail randomly, but it's very unlikely. If it fails a lot something
  // is probably wrong.
  EXPECT_LE(50, count_up);
  EXPECT_LE(50, count_down);
}
