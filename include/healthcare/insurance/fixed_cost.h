#ifndef _HEALTHCARE_INSURANCE_FIXED_COST_H_
#define _HEALTHCARE_INSURANCE_FIXED_COST_H_

#include <memory>

#include "healthcare/insurance.h"

namespace healthcare {
namespace insurance {

class FixedCost : public Insurance {
 public:
  explicit FixedCost(int cost) : cost_(cost) {}
  int GetCost(int age, int fitness, int health) const override { return cost_; }

 private:
  int cost_;
};

}  // namespace insurance
}  // namespace healthcaredp

#endif  // _HEALTHCARE_INSURANCE_FIXED_COST_H_
