#include <gtest/gtest.h>

#include <memory>

#include "healthcare/consumption_fractional.h"
#include "healthcare/degeneration_linear.h"
#include "healthcare/health_status.h"
#include "healthcare/job_flat.h"
#include "healthcare/regeneration_fractional.h"

class HealthStatusTest : public ::testing::Test {
 public:
  HealthStatusTest() : state_(), state_wounded_() {}

 protected:
  virtual void SetUp() {
    state_ = healthcare::HealthStatus(2, 80, 20);
    state_ = healthcare::HealthStatus(5, 5, 50);
  }

  healthcare::HealthStatus state_, state_wounded_;
};
