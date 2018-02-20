#ifndef _HEALTHCARE_PERIOD_RANGE_H_
#define _HEALTHCARE_PERIOD_RANGE_H_

namespace healthcare {

struct PeriodRange {
  int start;
  int end;
};

bool InRange(PeriodRange range, int period);
}  // namespace healthcare

#endif  // _HEALTHCARE_PERIOD_RANGE_H_
