#include "healthcare/age_range.h"

namespace healthcare {

bool InRange(AgeRange range, int age) {
  return age >= range.start && age <= range.end;
}

}  // namespace healthcare
