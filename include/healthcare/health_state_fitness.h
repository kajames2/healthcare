#ifndef _HEALTH_STATE_FITNESS_H_
#define _HEALTH_STATE_FITNESS_H_

#include "health_state_shock.h"

namespace healthcare {
struct HealthStateFitness : public HealthState{
  HealthStateFitness() : HealthStateShock(), fitness(0) {}
  int fitness;
};

} // namespace healthcare
#endif // _HEALTH_STATE_FITNESS_H_
