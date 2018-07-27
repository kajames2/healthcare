#include "healthcare/person.h"

#include <ostream>

namespace healthcare {

bool operator==(const Person& lhs, const Person& rhs) {
  return lhs.age == rhs.age && lhs.health == rhs.health && lhs.cash == rhs.cash;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
  return out << p.age << "," << p.health << "," << p.cash;
}

}  // namespace healthcare
