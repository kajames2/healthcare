#ifndef _HEALTHCARE_JOB_LINEAR_H_
#define _HEALTHCARE_JOB_LINEAR_H_

#include "healthcare/job.h"

namespace healthcare {

class JobLinear : public Job {
 public:
  explicit JobLinear(double job_rate);
  int GetEarnings(int age, int health) const override;

 private:
  double job_rate_;
};

}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_LINEAR_H_
