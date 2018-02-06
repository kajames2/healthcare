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

private:
  int CalculateHealthRegained(int health, int health_investment) const override;
  double k_;

};

} // namespace healthcare
#endif // _REGENERATION_FRACTIONAL_H_
