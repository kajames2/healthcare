#ifndef _PERIOD_RANGE_H_
#define _PERIOD_RANGE_H_

namespace healthcare {

struct PeriodRange {
  int start;
  int end;
};

bool InRange(PeriodRange range, int period);
} // namespace healthcare

#endif // _PERIOD_RANGE_H_
