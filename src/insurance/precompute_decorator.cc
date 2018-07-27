#include "healthcare/insurance/precompute_decorator.h"

namespace healthcare {
namespace insurance {

PrecomputeDecorator::PrecomputeDecorator(const Insurance &insure, int max_age,
                                         int n_fitnesses) {
  for (int i = 0; i < max_age; ++i) {
    cost_cache_.emplace_back(std::vector<std::array<int, 101>>(n_fitnesses));
  }
  Precompute(insure);
}

void PrecomputeDecorator::Precompute(const Insurance &insure) {
  for (int a = 0; a < cost_cache_.size(); ++a) {
    for (int f = 0; f < cost_cache_[0].size(); ++f) {
      for (int h = 0; h <= 100; ++h) {
        cost_cache_[a][f][h] = insure.GetCost(a + 1, f, h);
      }
    }
  }
}

}  // namespace insurance
}  // namespace healthcare
