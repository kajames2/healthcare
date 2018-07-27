#ifndef _HEALTHCARE_INSURANCE_ACTUARIAL_H_
#define _HEALTHCARE_INSURANCE_ACTUARIAL_H_

#include <cmath>
#include <memory>

#include "healthcare/degeneration.h"
#include "healthcare/insurance.h"
#include "healthcare/probability.h"
#include "healthcare/regeneration.h"
#include "healthcare/shock.h"

namespace healthcare {
namespace insurance {

class Actuarial : public Insurance {
 public:
  Actuarial(float multiplier, std::shared_ptr<const Regeneration> regen,
            std::shared_ptr<const Degeneration> degen,
            std::shared_ptr<const Shock> shock,
            std::shared_ptr<const Probability> prob);
  int GetCost(int age, int fitness, int health) const override;

 private:
  float multiplier_;
  std::shared_ptr<const Regeneration> regen_;
  std::shared_ptr<const Degeneration> degen_;
  std::shared_ptr<const Shock> shock_;
  std::shared_ptr<const Probability> prob_;
};

}  // namespace insurance
}  // namespace healthcare

#endif  // _HEALTHCARE_INSURANCE_ACTUARIAL_H_
