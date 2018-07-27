#include "healthcare/decision_fitness.h"

namespace healthcare {

int TotalSpending(DecisionFitness dec) {
  return dec.joy_spending + dec.health_spending + dec.fitness_spending +
         dec.insurance_spending;
}

std::ostream& operator<<(std::ostream& out, const DecisionFitness& d) {
  return out << d.health_spending << "," << d.joy_spending << ","
             << d.fitness_spending << "," << d.insurance_spending;
}

}  // namespace healthcare
