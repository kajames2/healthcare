#include "healthcare/health_state.h"
#include "healthcare/regeneration.h"

#include <algorithm>

namespace healthcare {

void HealthState::GainHealth(int health_gain) {
  health_ += health_gain;
  health_ = std::min(health_, 100);
}

void HealthState::LoseHealth(int health_loss) {
  health_ -= health_loss;
  if (health_ <= 0) {
    health_ = 0;
    is_dead_ = true;
  }
}


// void HealthState::Harvest(Harvest* harvest) {
  
// }

void HealthState::Age() {
  age_++;
}

void HealthState::RegainHealth(Regeneration* regen) {
  int health_gained = regen->GetHealthRegained(health_, health_investment_);
  GainHealth(health_gained);
}

bool HealthState::IsAlive() const { return health_ > 0; }
}  // namespace healthcare
