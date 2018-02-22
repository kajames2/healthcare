#ifndef _HEALTHCARE_AGE_RANGE_H_
#define _HEALTHCARE_AGE_RANGE_H_

namespace healthcare {

struct AgeRange {
  int start;
  int end;
};

bool InRange(AgeRange range, int age);
}  // namespace healthcare

#endif  // _HEALTHCARE_AGE_RANGE_H_
