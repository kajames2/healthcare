#ifndef _CONSUMPTION_FRACTIONAL_H_
#define _CONSUMPTION_FRACTIONAL_H_

#include "consumption_cached.h"

#include <array>
#include <vector>
#include <memory>

namespace healthcare {

class ConsumptionFractional : public ConsumptionCached {
public:
  ConsumptionFractional(double j);
  ConsumptionFractional(double j, int max_investment);

private:
  double CalculateLifeEnjoyment(int health, int life_investment) const override;
  double j_;
};

} // namespace healthcare
#endif // _CONSUMPTION_FRACTIONAL_H_
