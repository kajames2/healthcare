#ifndef _HEALTHCARE_JOB_PRECOMPUTE_DECORATOR_H_
#define _HEALTHCARE_JOB_PRECOMPUTE_DECORATOR_H_

#include "healthcare/job.h"

#include <array>

namespace healthcare {
namespace job {

template <int MAXAGE>
class PrecomputeDecorator : public Job {
 public:
  explicit PrecomputeDecorator(const Job &job);
  inline int GetEarnings(int age, int health) const override;

 private:
  void Precompute(const Job &job);
  std::array<std::array<double, 101>, MAXAGE> cache_;
};

template <int MAXAGE>
PrecomputeDecorator<MAXAGE>::PrecomputeDecorator(const Job &job) {
  Precompute(job);
}

template <int MAXAGE>
int PrecomputeDecorator<MAXAGE>::GetEarnings(int age, int health) const {
  return cache_[age - 1][health];
}

template <int MAXAGE>
void PrecomputeDecorator<MAXAGE>::Precompute(const Job &job) {
  for (int a = 0; a < cache_.size(); ++a) {
    for (int h = 0; h <= 100; ++h) {
      cache_[a][h] = job.GetEarnings(a + 1, h);
    }
  }
}

}  // namespace job
}  // namespace healthcare
#endif  // _HEALTHCARE_JOB_PRECOMPUTE_DECORATOR_H_
