#ifndef _HEALTHCARE_CONSUMPTION_LOGISTIC_H_
#define _HEALTHCARE_CONSUMPTION_LOGISTIC_H_

#include "healthcare/consumption.h"

namespace healthcare {
namespace consumption {

class Logistic : public Consumption {
 public:
  explicit Logistic(double k);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  double k_;
};

}  // namespace consumption
}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_LOGISTIC_H_
