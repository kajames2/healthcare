#ifndef _HEALTHCARE_ENJOYMENT_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_ENJOYMENT_PRECOMPUTE_DECORATOR_H_

#include <array>
#include <vector>

#include "healthcare/enjoyment.h"

namespace healthcare {
namespace enjoyment {

class PrecomputeDecorator : public Enjoyment {
 public:
  explicit PrecomputeDecorator(const Enjoyment &enjoyment);
  PrecomputeDecorator(const Enjoyment &enjoyment, int max_investment);
  inline double GetEnjoyment(int health, int life_investment) const override {
    return cache_[life_investment][health];
  }

 private:
  void Precompute(const Enjoyment &enjoyment);
  std::vector<std::array<double, 101>> cache_;
};

}  // namespace enjoyment
}  // namespace healthcare
#endif  // _HEALTHCARE_ENJOYMENT_PRECOMPUTE_DECORATOR_H_
