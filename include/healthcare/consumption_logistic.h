#ifndef _CONSUMPTION_LOGISTIC_H_
#define _CONSUMPTION_LOGISTIC_H_

#include "consumption.h"

namespace healthcare {

class ConsumptionLogistic : public Consumption {
public:
  explicit ConsumptionLogistic(double k);
  double GetLifeEnjoyment(int health, int life_investment) const override;

private:
  double k_;
};

} // namespace healthcare
#endif // _CONSUMPTION_LOGISTIC_H_
