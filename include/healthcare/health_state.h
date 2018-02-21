#ifndef _HEALTHCARE_HEALTH_STATE_H_
#define _HEALTHCARE_HEALTH_STATE_H_

namespace healthcare {
struct HealthState {
  HealthState()
      : period(0),
        health(0),
        cash(0),
        total_working_harvest(0),
        harvest(0),
        life_investment(0),
        health_investment(0),
        end_health(0),
        end_cash(0),
        investment_cash(0),
        investment_health(0),
        life_enjoyment(0) {}
  HealthState(int p, int h, int c, int twh)
      : period(p),
        health(h),
        cash(c),
        total_working_harvest(twh),
        harvest(0),
        life_investment(0),
        health_investment(0),
        end_health(0),
        end_cash(0),
        investment_cash(0),
        investment_health(0),
        life_enjoyment(0) {}
  
  int period;
  int health;
  int cash;
  int total_working_harvest;

  int investment_cash;
  int investment_health;

  int life_investment;
  int health_investment;
  int harvest;
  int end_health;
  int end_cash;
  double life_enjoyment;
};

bool IsAlive(const HealthState &state);
}  // namespace healthcare
#endif  // _HEALTHCARE_HEALTH_STATE_H_
