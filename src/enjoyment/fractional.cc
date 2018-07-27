#include "healthcare/enjoyment/fractional.h"

namespace healthcare {
namespace enjoyment {
Fractional::Fractional(double j) : j_(j) {}

double Fractional::GetEnjoyment(int health, int life_investment) const {
  return health * life_investment / (life_investment + j_);
}

}  // namespace enjoyment
}  // namespace healthcare
