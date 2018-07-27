#ifndef _HEALTHCARE_FITNESS_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_FITNESS_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/fitness.h"

namespace healthcare {
namespace fitness {

class PrecomputeDecorator : public Fitness {
 public:
  explicit PrecomputeDecorator(const Fitness &fitness, int n_fitnesses,
                               int max_investment = 300);
  inline int GetFitness(int fitness_investment) const override {
    return cache_[fitness_investment];
  }
  inline int GetCost(int fitness) const override {
    return cost_cache_[fitness];
  }

 private:
  void Precompute(const Fitness &fitness);
  std::vector<int> cache_;
  std::vector<int> cost_cache_;
};

}  // namespace fitness
}  // namespace healthcare
#endif  // _HEALTHCARE_FITNESS_PRECOMPUTE_DECORATOR_H_
