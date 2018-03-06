#include "healthcare/consumption/fractional.h"

namespace healthcare {
namespace consumption {
Fractional::Fractional(double j) : j_(j) {}

double Fractional::GetLifeEnjoyment(int health, int life_investment) const {
  return health * life_investment / (life_investment + j_);
}

}  // namespace consumption
}  // namespace healthcare
