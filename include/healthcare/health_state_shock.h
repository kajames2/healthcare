#ifndef _HEALTHCARE_HEALTH_STATE_SHOCK_H_
#define _HEALTHCARE_HEALTH_STATE_SHOCK_H_

#include "healthcare/health_state.h"

namespace healthcare {
struct HealthStateShock : public HealthState {
  HealthStateShock() : HealthState(), health_shock(0) {}
  int health_shock;
};
}  // namespace healthcare
#endif  // _HEALTHCARE_HEALTH_STATE_SHOCK_H_
