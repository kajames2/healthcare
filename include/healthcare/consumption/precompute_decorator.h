#ifndef _HEALTHCARE_CONSUMPTION_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_CONSUMPTION_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/consumption.h"

namespace healthcare {
namespace consumption {

class PrecomputeDecorator : public Consumption {
 public:
  explicit PrecomputeDecorator(const Consumption &consumption);
  PrecomputeDecorator(const Consumption &consumption, int max_investment);
  double GetLifeEnjoyment(int health, int life_investment) const override;

 private:
  void Precompute(const Consumption &consumption);
  std::vector<std::array<double, 101>> cache_;
};

}  // namespace consumption
}  // namespace healthcare
#endif  // _HEALTHCARE_CONSUMPTION_PRECOMPUTE_DECORATOR_H_
