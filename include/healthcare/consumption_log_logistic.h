#ifndef _HEALTHCARE_CONSUMPTION_LOG_LOGISTIC_H_
#define _HEALTHCARE_CONSUMPTION_LOG_LOGISTIC_H_

#include "healthcare/consumption.h"

namespace healthcare {

class ConsumptionLogLogistic : public Consumption {
 public:
  ConsumptionLogLogistic(double alpha, double beta, double c);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  double alpha_, beta_, c_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_LOG_LOGISTIC_H_
