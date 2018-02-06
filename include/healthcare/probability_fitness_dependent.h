#ifndef _PROBABILITY_FITNESS_MODULATED_H_
#define _PROBABILITY_FITNESS_MODULATED_H_

#include "probability_strategy.h"
#include <vector>

namespace healthcaredp {

template <typename T>
class ProbabilityFitnessModulated : public genericdp::ProbabilityStrategy<T> {
public:
  ProbabilityFitnessModulated(
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
