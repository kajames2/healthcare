#ifndef _FITNESS_MODULATED_PROBABILITY_H_
#define _FITNESS_MODULATED_PROBABILITY_H_

#include "fitness_dp_health_state.h"
#include "probability_strategy.h"
#include <vector>

namespace healthcaredp {

template <typename T>
class FitnessModulatedProbability : public genericdp::ProbabilityStrategy<T> {
public:
  FitnessModulatedProbability(
      std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob,
      std::vector<double> mods)
      : prob_(prob), mods_(mods) {}
  double GetProbability(const T &state) const override {
    return mods_[state.fitness] * prob_.GetProbability(state);
  }

private:
  std::shared_ptr<genericdp::ProbabilityStrategy<T>> prob_;
  std::vector<double> mods_;
};

} // namespace genericdp

#endif //_FITNESS_MODULATED_PROBABILITY_H_
