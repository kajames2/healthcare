#ifndef _HEALTHCARE_HEALTH_STATE_FITNESS_H_
#define _HEALTHCARE_HEALTH_STATE_FITNESS_H_

#include "healthcare/health_state_shock.h"

namespace healthcare {
struct HealthStateFitness : public HealthStateShock {
  HealthStateFitness() : HealthStateShock(), fitness(0) {}
  int fitness;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_HEALTH_STATE_FITNESS_H_
