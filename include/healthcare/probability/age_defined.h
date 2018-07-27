#ifndef _HEALTHCARE_PROBABILITY_AGE_DEFINED_H_
#define _HEALTHCARE_PROBABILITY_AGE_DEFINED_H_

#include <vector>

#include "healthcare/probability.h"

namespace healthcare {
namespace probability {

template <class T>
std::vector<T> JoinVectors(std::vector<T> v1, std::vector<T> v2) {
  v1.reserve(v1.size() + v2.size());
  v1.insert(v1.end(), v2.begin(), v2.end());
  return v1;
}

class AgeDefined : public Probability {
 public:
  explicit AgeDefined(std::vector<float> probs) : probs_(probs) {}
  static AgeDefined TwoTiered(float p1, int n_p1_periods, float p2,
                              int max_age) {
    return AgeDefined(
        JoinVectors(std::vector<float>(n_p1_periods, p1),
                    std::vector<float>(max_age - n_p1_periods, p2)));
  }
  float operator()(int age) const override { return probs_[age - 1]; }

 private:
  std::vector<float> probs_;
};

}  // namespace probability
}  // namespace healthcare

#endif  // _HEALTHCARE_PROBABILITY_AGE_DEFINED_H_
