#include "healthcare/job/composite.h"

#include <memory>
#include <utility>
#include <vector>

#include "healthcare/job/ranged_decorator.h"

namespace healthcare {
namespace job {

Composite::Composite() : jobs_() {}

int Composite::GetEarnings(int age, int health) const {
  int net_job = 0;
  for (auto& job : jobs_) {
    net_job += job.GetEarnings(age, health);
  }
  return net_job;
}

void Composite::AddJob(RangedDecorator job) { jobs_.push_back(std::move(job)); }

}  // namespace job
}  // namespace healthcare
