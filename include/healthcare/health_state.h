#ifndef _HEALTH_STATE_H_
#define _HEALTH_STATE_H_

namespace healthcare {
struct HealthState {
  HealthState() : period(0), health(0), cash(0), total_working_harvest(0) {}
  HealthState(int p, int h, int c, int twh) : period(p), health(h), cash(c), total_working_harvest(twh) {}
  int period;
  int health;
  int cash;
  int total_working_harvest;
};

bool IsAlive(const HealthState &state);
} // namespace healthcare
#endif // _HEALTH_STATE_H_
