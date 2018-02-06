#ifndef _PROBABILITY_PERIOD_DEFINED_H_
#define _PROBABILITY_PERIOD_DEFINED_H_

#include "probability_strategy.h"
#include <vector>

namespace healthcaredp {

template <typename T>
class ProbabilityPeriodDefined : public genericdp::ProbabilityStrategy<T> {
public:
  ProbabilityPeriodDefined(std::vector<double> probs) : probs_(probs) {}
  double GetProbability(const T &state) const override {
    return probs_[state.period];
  }

private:
  std::vector<double> probs_;
};

} // namespace genericdp

#endif //_PROBABILITY_PERIOD_DEFINED_H_
