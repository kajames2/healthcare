#ifndef _HEALTHCARE_DECISION_FITNESS_H_
#define _HEALTHCARE_DECISION_FITNESS_H_

#include <ostream>

namespace healthcare {

struct DecisionFitness {
  int health_spending = 0;
  int joy_spending = 0;
  int fitness_spending = 0;
  int insurance_spending = 0;
};

int TotalSpending(DecisionFitness dec);

std::ostream& operator<<(std::ostream& out, const DecisionFitness& d);

}  // namespace healthcare
#endif  // _HEALTHCARE_DECISION_FITNESS_H_
