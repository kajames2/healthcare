#ifndef _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class PrecomputeDecorator : public Regeneration {
 public:
  explicit PrecomputeDecorator(const Regeneration &regen);
  PrecomputeDecorator(const Regeneration &regen, int max_investment);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  void Precompute(const Regeneration &regen);
  std::vector<std::array<int, 101>> regen_cache_;
  std::array<std::array<int, 101>, 101> cost_cache_;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_
