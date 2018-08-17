#include "benchmark/benchmark.h"
#include "models/ising.h"

static void BM_METROPOLIS(benchmark::State &state) {
  using namespace isinggraph::ising;
  Ising<Metropolis, isinggraph::Grid2D> ising_grid(100);
  for (auto _ : state) {
    for (int i = 0; i < 10000; ++i) ising_grid.update(1.0);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_METROPOLIS);
