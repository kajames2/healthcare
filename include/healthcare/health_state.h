#ifndef _HEALTH_STATE_H_
#define _HEALTH_STATE_H_

#include <ostream>

namespace healthcare {
struct HealthState {
  HealthState() : period(0), cash(0), health(0), total_working_harvest(0) {}
  HealthState(int p, int h, int c, int twh)
      : period(p), health(h), cash(c), total_working_harvest(twh) {}
  int period;
  int cash;
  int health;
  int total_working_harvest;

  bool operator==(const HealthState &other) const {
    return period == other.period && cash == other.cash &&
           health == other.health &&
           total_working_harvest == other.total_working_harvest;
  }
};

bool IsAlive(const HealthState &state);
} // namespace healthcare
#endif // _HEALTH_STATE_H_
