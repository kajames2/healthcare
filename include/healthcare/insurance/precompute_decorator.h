#ifndef _HEALTHCARE_INSURANCE_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_INSURANCE_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/insurance.h"

namespace healthcare {
namespace insurance {

class PrecomputeDecorator : public Insurance {
 public:
  PrecomputeDecorator(const Insurance &insure, int max_age, int n_fitnesses);
  int GetCost(int age, int fitness, int health) const override {
    return cost_cache_[age - 1][fitness][health];
  }

 private:
  void Precompute(const Insurance &insure);
  std::vector<std::vector<std::array<int, 101>>> cost_cache_;
};

}  // namespace insurance
}  // namespace healthcare
#endif  // _HEALTHCARE_INSURANCE_PRECOMPUTE_DECORATOR_H_
