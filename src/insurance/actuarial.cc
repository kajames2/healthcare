#include "healthcare/insurance/actuarial.h"

namespace healthcare {
namespace insurance {

Actuarial::Actuarial(float multiplier,
                     std::shared_ptr<const Regeneration> regen,
                     std::shared_ptr<const Degeneration> degen,
                     std::shared_ptr<const Shock> shock,
                     std::shared_ptr<const Probability> prob)
    : multiplier_(multiplier),
      regen_(std::move(regen)),
      degen_(std::move(degen)),
      shock_(std::move(shock)),
      prob_(std::move(prob)) {}

int Actuarial::GetCost(int age, int fitness, int health) const {
  int shock_size = (*shock_)(fitness);
  int degen_size = degen_->GetDegeneration(age, health);
  return std::round(
      multiplier_ * ((*prob_)(age)) *
      regen_->GetRegainCost(health - degen_size - shock_size, shock_size));
}

}  // namespace insurance
}  // namespace healthcare
