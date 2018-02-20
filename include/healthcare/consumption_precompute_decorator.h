#ifndef _CONSUMPTION_PRECOMPUTE_DECORATOR_H_
#define _CONSUMPTION_PRECOMPUTE_DECORATOR_H_

#include "consumption.h"

#include <array>
#include <vector>

namespace healthcare {
class ConsumptionPrecomputeDecorator : public Consumption {
public:
  explicit ConsumptionPrecomputeDecorator(const Consumption &consumption);
  ConsumptionPrecomputeDecorator(const Consumption &consumption, int max_investment);
  virtual double GetLifeEnjoyment(int health,
                                  int life_investment) const override;

private:
  void Precompute(const Consumption& consumption);
  std::vector<std::array<double, 101>> cache_;
};

} // namespace healthcare
#endif // _CONSUMPTION_PRECOMPUTE_DECORATOR_H_
