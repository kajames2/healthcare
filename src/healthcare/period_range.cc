#include "period_range.h"

namespace healthcare {

bool InRange(PeriodRange range, int period) {
  return period >= range.start && period <= range.end;
}

}  // namespace healthcare
