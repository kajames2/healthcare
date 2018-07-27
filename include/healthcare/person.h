#ifndef _HEALTHCARE_PERSON_H_
#define _HEALTHCARE_PERSON_H_

#include <ostream>

namespace healthcare {
struct Person {
  int age = 0;
  int health = 0;
  int cash = 0;
};

bool operator==(const Person& lhs, const Person& rhs);
std::ostream& operator<<(std::ostream& out, const Person& p);

}  // namespace healthcare
#endif  // _HEALTHCARE_PERSON_H_
