#ifndef _HEALTHCARE_CONSUMPTION_INCREASING_DECAY_H_
#define _HEALTHCARE_CONSUMPTION_INCREASING_DECAY_H_

#include "healthcare/consumption.h"

namespace healthcare {
namespace consumption {

class IncreasingDecay : public Consumption {
 public:
  IncreasingDecay(double alpha, double beta, double c);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  double alpha_;
  double beta_;
  double c_;
};

}  // namespace consumption
}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_INCREASING_DECAY_H_
