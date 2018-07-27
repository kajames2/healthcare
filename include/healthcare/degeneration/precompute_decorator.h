#ifndef _HEALTHCARE_DEGENERATION_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_DEGENERATION_PRECOMPUTE_DECORATOR_H_

#include "healthcare/degeneration.h"

#include <array>
#include <vector>

namespace healthcare {
namespace degeneration {

class PrecomputeDecorator : public Degeneration {
 public:
  explicit PrecomputeDecorator(const Degeneration &degeneration, int max_age);
  int GetDegeneration(int age, int health) const override {
    return cache_[age - 1][health];
  }

 private:
  void Precompute(const Degeneration &degeneration);
  std::vector<std::array<double, 101>> cache_;
};

}  // namespace degeneration
}  // namespace healthcare
#endif  // _HEALTHCARE_DEGENERATION_PRECOMPUTE_DECORATOR_H_
