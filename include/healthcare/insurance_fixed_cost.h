#ifndef _HEALTHCARE_INSURANCE_FIXED_COST_H_
#define _HEALTHCARE_INSURANCE_FIXED_COST_H_

#include <memory>

#include "healthcare/insurance_calculator.h"

namespace healthcaredp {

template <typename T>
class InsuranceFixedCost : public InsuranceCalculator<T> {
 public:
  explicit InsuranceFixedCost(int cost) : cost_(cost) {}
  int GetInsuranceCost(const T &state) const override { return cost_; }

 private:
  int cost_;
};

}  // namespace healthcaredp

#endif  // _HEALTHCARE_INSURANCE_FIXED_COST_H_
