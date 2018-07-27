#ifndef _HEALTHCARE_FITNESS_DEFINED_COSTS_H_
#define _HEALTHCARE_FITNESS_DEFINED_COSTS_H_

#include <algorithm>
#include <vector>

#include "healthcare/fitness.h"

namespace healthcare {
namespace fitness {
class DefinedCosts : public Fitness {
 public:
  DefinedCosts(std::vector<int> costs) : costs_(costs) {}
  int GetFitness(int investment) const override {
    auto it =
        std::find_if(costs_.begin(), costs_.end(),
                     [investment](int cost) { return cost > investment; });
    return std::distance(costs_.begin(), it) - 1;
  }
  int GetCost(int fitness) const override { return costs_[fitness]; }

 private:
  std::vector<int> costs_;
};

}  // namespace fitness
}  // namespace healthcare
#endif  // _HEALTHCARE_FITNESS_DEFINED_COSTS_H_
