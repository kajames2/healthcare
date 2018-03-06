#ifndef _HEALTHCARE_JOB_LINEAR_H_
#define _HEALTHCARE_JOB_LINEAR_H_

#include "healthcare/job.h"

namespace healthcare {
namespace job {

class Linear : public Job {
 public:
  explicit Linear(double rate);
  int GetEarnings(int age, int health) const override;

 private:
  double rate_;
};

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_LINEAR_H_
