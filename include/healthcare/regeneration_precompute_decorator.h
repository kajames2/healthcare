#ifndef _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/regeneration.h"

namespace healthcare {
class RegenerationPrecomputeDecorator : public Regeneration {
 public:
  explicit RegenerationPrecomputeDecorator(const Regeneration &regen);
  RegenerationPrecomputeDecorator(const Regeneration &regen,
                                  int max_investment);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  void Precompute(const Regeneration &regen);
  std::vector<std::array<int, 101>> cache_;
  std::array<std::array<int, 101>, 101> cache2_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_PRECOMPUTE_DECORATOR_H_
