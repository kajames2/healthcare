#ifndef _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_
#define _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_

#include "healthcare/consumption.h"

namespace healthcare {
namespace consumption {

class Fractional : public Consumption {
 public:
  explicit Fractional(double j);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  double j_;
};

}  // namespace consumption
}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_FRACTIONAL_H_