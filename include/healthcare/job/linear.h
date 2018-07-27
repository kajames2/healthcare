#ifndef _HEALTHCARE_JOB_LINEAR_H_
#define _HEALTHCARE_JOB_LINEAR_H_

#include "healthcare/job.h"

namespace healthcare {
namespace job {

class Linear : public Job {
 public:
  explicit Linear(float rate, int intercept = 0);
  int GetEarnings(int age, int health) const override;

 private:
  const float rate_;
  const int intercept_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_LINEAR_H_
