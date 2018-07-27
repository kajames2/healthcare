#ifndef _HEALTHCARE_ENJOYMENT_INCREASING_DECAY_H_
#define _HEALTHCARE_ENJOYMENT_INCREASING_DECAY_H_

#include "healthcare/enjoyment.h"

namespace healthcare {
namespace enjoyment {

class IncreasingDecay : public Enjoyment {
 public:
  IncreasingDecay(double alpha, double beta, double c);
  double GetEnjoyment(int health, int life_investment) const override;

 private:
  double alpha_;
  double beta_;
  double c_;
};

}  // namespace enjoyment
}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_INCREASING_DECAY_H_
