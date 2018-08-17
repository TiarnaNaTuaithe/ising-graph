#pragma once
/**
@file
@brief This file contains a function to measure a model's susceptibility
*/

#include <iostream>

namespace isinggraph {

//! Measures the average susceptibility over a range of beta
/*!
  Measures the susceptibility of an arbitrary model over a specified range of
  beta
  @param model The model object to use for the simulation
  @param beta_low The lower bound for the range of beta values
  @param beta_high The upper bound for the range of beta values
  @param steps The number of values of beta to sample from the range
  @param avg_steps The number of readings to average over for each measurement
  @param therm_steps The number of updates to do between each measurement
  (called 'thermalisation')
  @param print print the calculated values. We might not want to do this for a
  benchmark.
*/
template <typename T>
void measure_susceptibility(T& model, double const& beta_low,
                            double const& beta_high, int steps, int avg_steps,
                            int therm_steps, bool print = false) {
  auto beta = beta_low;
  auto const increment = (beta_high - beta_low) / steps;

  auto thermalise = [&]() {
    for (int i = 0; i < therm_steps; ++i) {
      model.update(beta);
    }
  };

  while (beta < beta_high) {
    double measurement = 0.0;
    for (int i = 0; i < avg_steps; ++i) {
      thermalise();
      measurement += model.susceptibility();
    }

    if (print) {
      std::cout << beta << '\t' << measurement / avg_steps << '\n';
    }
    beta += increment;
  }
}

}  // namespace isinggraph
