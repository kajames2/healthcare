#ifndef _HEALTHCARE_SHOCK_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_SHOCK_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/shock.h"

namespace healthcare {
namespace shock {

class PrecomputeDecorator : public Shock {
 public:
  explicit PrecomputeDecorator(const Shock &shock, int n_fitnesses);
  inline int operator()(int fitness) const override { return cache_[fitness]; }

 private:
  void Precompute(const Shock &shock);
  std::vector<int> cache_;
};

}  // namespace shock
}  // namespace healthcare
#endif  // _HEALTHCARE_SHOCK_PRECOMPUTE_DECORATOR_H_
