#include "healthcare/health_status.h"

#include <algorithm>

#include "healthcare/consumption.h"
#include "healthcare/degeneration.h"
#include "healthcare/job.h"
#include "healthcare/regeneration.h"

namespace healthcare {

HealthStatus::HealthStatus()
    : age_(0),
      health_(0),
      cash_(0),
      joy_spending_(0),
      health_spending_(0),
      life_enjoyment_(0),
      is_dead_(true) {}
HealthStatus::HealthStatus(int a, int h, int c)
    : age_(a),
      health_(h),
      cash_(c),
      joy_spending_(0),
      health_spending_(0),
      life_enjoyment_(0),
      is_dead_(a <= 0) {}

void HealthStatus::Work(const Job* job) {
  cash_ += job->GetEarnings(age_, health_);
}

void HealthStatus::RegainHealth(const Regeneration* regen) {
  if (IsAlive()) {
    int health_gained = regen->GetHealthRegained(health_, health_spending_);
    GainHealth(health_gained);
    cash_ -= health_spending_;
  }
}

void HealthStatus::Degenerate(const Degeneration* degen) {
  LoseHealth(degen->GetDegeneration(age_));
}

void HealthStatus::AdvanceInAge() {
  age_++;
  health_spending_ = 0;
  joy_spending_ = 0;
  life_enjoyment_ = 0;
}

void HealthStatus::Consume(const Consumption* consume) {
  if (IsAlive()) {
    life_enjoyment_ += consume->GetLifeEnjoyment(health_, joy_spending_);
    cash_ -= joy_spending_;
  }
}

void HealthStatus::GainHealth(int health_gain) {
  health_ += health_gain;
  health_ = std::min(health_, 100);
}

void HealthStatus::LoseHealth(int health_loss) {
  health_ -= health_loss;
  if (health_ <= 0) {
    health_ = 0;
    is_dead_ = true;
  }
}
}  // namespace healthcare
