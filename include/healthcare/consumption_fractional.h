#ifndef _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_
#define _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_

#include "healthcare/consumption.h"

namespace healthcare {

class ConsumptionFractional : public Consumption {
 public:
  explicit ConsumptionFractional(double j);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  double j_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_
