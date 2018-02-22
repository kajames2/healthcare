#ifndef _HEALTHCARE_PROBABILITY_STRATEGY_H_
#define _HEALTHCARE_PROBABILITY_STRATEGY_H_

namespace genericdp {

template <typename T>
class ProbabilityStrategy {
 public:
  virtual double GetProbability(const T &state) const = 0;
  virtual ~ProbabilityStrategy() {}
};

}  // namespace genericdp

#endif  // _HEALTHCARE_PROBABILITY_STRATEGY_H_
