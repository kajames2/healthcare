#include "healthcare/fitness/precompute_decorator.h"

#include <vector>

namespace healthcare {
namespace fitness {

PrecomputeDecorator::PrecomputeDecorator(const Fitness &fitness,
                                         int n_fitnesses, int max_investment)
    : cache_(max_investment + 1), cost_cache_(n_fitnesses) {
  Precompute(fitness);
}

void PrecomputeDecorator::Precompute(const Fitness &fitness) {
  for (int fi = 0; fi < cache_.size(); ++fi) {
    cache_[fi] = fitness.GetFitness(fi);
  }
  for (int fit = 0; fit < cost_cache_.size(); ++fit) {
    cost_cache_[fit] = fitness.GetCost(fit);
  }
}

}  // namespace fitness
}  // namespace healthcare
