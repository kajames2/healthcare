#ifndef _INSURANCE_FIXED_COST_H_
#define _INSURANCE_FIXED_COST_H_

#include "insurance_calculator.h"
#include <memory>

namespace healthcaredp {

template <typename T> class InsuranceFixedCost : public InsuranceCalculator<T> {
public:
  explicit InsuranceFixedCost(int cost) : cost_(cost) {}
  int GetInsuranceCost(const T &state) const override { return cost_; }

private:
  int cost_;
};

} // namespace genericdp

#endif // _INSURANCE_FIXED_COST_H_
