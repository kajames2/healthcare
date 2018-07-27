#ifndef _HEALTHCARE_INSURANCE_SCALE_DECORATOR_H_
#define _HEALTHCARE_INSURANCE_SCALE_DECORATOR_H_

#include <cmath>
#include <memory>

#include "healthcare/insurance.h"

namespace healthcare {
namespace insurance {

class ScaleDecorator : public Insurance {
 public:
  explicit ScaleDecorator(float scale, std::unique_ptr<const Insurance> insure)
      : scale_(scale), insure_(std::move(insure)) {}
  inline int GetCost(int age, int fitness, int health) const override {
    return std::round(scale_ * insure_->GetCost(age, fitness, health));
  };

 private:
  float scale_;
  std::unique_ptr<const Insurance> insure_;
};

}  // namespace insurance
}  // namespace healthcare
#endif  // _HEALTHCARE_INSURANCE_SCALE_DECORATOR_H_
