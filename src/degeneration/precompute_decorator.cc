#include "healthcare/degeneration/precompute_decorator.h"

#include <array>
#include <vector>

namespace healthcare {
namespace degeneration {

PrecomputeDecorator::PrecomputeDecorator(const Degeneration &degeneration,
                                         int max_age)
    : cache_(max_age) {
  Precompute(degeneration);
}

void PrecomputeDecorator::Precompute(const Degeneration &degeneration) {
  for (int a = 0; a < cache_.size(); ++a) {
    for (int h = 0; h <= 100; ++h) {
      cache_[a][h] = degeneration.GetDegeneration(a + 1, h);
    }
  }
}

}  // namespace degeneration
}  // namespace healthcare
