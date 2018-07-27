#include "healthcare/person_fitness.h"

#include <ostream>

namespace healthcare {

bool operator==(const PersonFitness& lhs, const PersonFitness& rhs) {
  return lhs.age == rhs.age && lhs.health == rhs.health &&
         lhs.cash == rhs.cash && lhs.payout_code == rhs.payout_code;
}

std::ostream& operator<<(std::ostream& out, const PersonFitness& p) {
  return out << p.age << "," << p.health << "," << p.cash << ","
             << p.payout_code;
}

}  // namespace healthcare
