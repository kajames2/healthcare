#ifndef _CONSUMPTION_FRACTIONAL_H_
#define _CONSUMPTION_FRACTIONAL_H_

#include "consumption_cached.h"

#include <array>
#include <memory>
#include <vector>

namespace healthcare {

class ConsumptionFractional : public ConsumptionCached {
public:
  ConsumptionFractional(double j);
  ConsumptionFractional(double j, int max_investment);

protected:
  double CalculateLifeEnjoyment(int health, int life_investment) const override;

private:
  double j_;
};

} // namespace healthcare
#endif // _CONSUMPTION_FRACTIONAL_H_
