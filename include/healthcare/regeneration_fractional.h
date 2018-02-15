#ifndef _REGENERATION_FRACTIONAL_H_
#define _REGENERATION_FRACTIONAL_H_

#include "regeneration_cached.h"
#include <array>
#include <vector>

namespace healthcare {

class RegenerationFractional : public RegenerationCached {
public:
  RegenerationFractional(double k);
  RegenerationFractional(double k, int max_investment);

protected:
  int CalculateHealthRegained(int health, int health_investment) const override;
  int CalculateRegainCost(int health, int health_regained) const override;

 private:
  double k_;

};

} // namespace healthcare
#endif // _REGENERATION_FRACTIONAL_H_
