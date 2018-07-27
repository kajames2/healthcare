#ifndef _HEALTHCARE_PERSON_FITNESS_H_
#define _HEALTHCARE_PERSON_FITNESS_H_

#include <ostream>

namespace healthcare {
struct PersonFitness {
  int age = 0;
  int health = 0;
  int cash = 0;
  int payout_code = 0;
};

bool operator==(const PersonFitness& lhs, const PersonFitness& rhs);
std::ostream& operator<<(std::ostream& out, const PersonFitness& p);

}  // namespace healthcare
#endif  // _HEALTHCARE_PERSON_FITNESS_H_
