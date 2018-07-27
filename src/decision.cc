#include "healthcare/decision.h"

#include <ostream>

namespace healthcare {

int TotalSpending(Decision dec) {
  return dec.joy_spending + dec.health_spending;
}

std::ostream& operator<<(std::ostream& out, const Decision& d) {
  return out << d.health_spending << "," << d.joy_spending;
}

}  // namespace healthcare
