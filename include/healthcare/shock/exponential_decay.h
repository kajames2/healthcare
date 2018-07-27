#ifndef _HEALTHCARE_SHOCK_EXPONENTIAL_DECAY_H_
#define _HEALTHCARE_SHOCK_EXPONENTIAL_DECAY_H_

#include "healthcare/shock.h"

namespace healthcare {
namespace shock {

class ExponentialDecay : public Shock {
 public:
  ExponentialDecay(int max_shock, float rate) : max_shock_(max_shock), rate_(rate) {}
  int operator()(int fitness) const override;

 private:
  int max_shock_;
  float rate_;
};

}  // namespace shock
}  // namespace healthcare

#endif  // _HEALTHCARE_SHOCK_EXPONENTIAL_DECAY_H_
