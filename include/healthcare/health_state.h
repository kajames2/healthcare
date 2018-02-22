#ifndef _HEALTHCARE_HEALTH_STATE_H_
#define _HEALTHCARE_HEALTH_STATE_H_

#include "healthcare/regeneration.h"

namespace healthcare {
class HealthState {
 public:
  HealthState()
      : age_(0),
        health_(0),
        cash_(0),
        harvest_(0),
        life_investment_(0),
        health_investment_(0),
        life_enjoyment_(0) {}
  HealthState(int p, int h, int c)
      : age_(p),
        health_(h),
        cash_(c),
        harvest_(0),
        life_investment_(0),
        health_investment_(0),
        life_enjoyment_(0) {}

  void GainHealth(int health_gain);
  void LoseHealth(int health_lose);
  void RegainHealth(Regeneration* regen);
  void Age();
  bool IsAlive() const;
  int GetPeriod() const { return age_; }
  int GetHealthInvestment() const { return health_investment_; }
  int GetLifeInvestment() const { return life_investment_; }
  int GetHealth() const { return health_; }

 private:
  bool is_dead_;
  int age_;
  int health_;
  int cash_;
  int total_working_harvest_;

  int life_investment_;
  int health_investment_;
  int harvest_;
  double life_enjoyment_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_HEALTH_STATE_H_
