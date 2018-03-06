#ifndef _HEALTHCARE_REGENERATION_FRACTIONAL_H_
#define _HEALTHCARE_REGENERATION_FRACTIONAL_H_

#include "healthcare/regeneration.h"

namespace healthcare {
namespace regeneration {

class Fractional : public Regeneration {
 public:
  explicit Fractional(double k);
  int GetHealthRegained(int health, int health_investment) const override;
  int GetRegainCost(int health, int health_regained) const override;

 private:
  double k_;
};

}  // namespace regeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_REGENERATION_FRACTIONAL_H_
