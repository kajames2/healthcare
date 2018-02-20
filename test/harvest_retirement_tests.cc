#include "healthcare/harvest_retirement.h"

#include <memory>

#include <gtest/gtest.h>

#include "healthcare/health_state.h"

class HarvestRetirementTest : public ::testing::Test {
 public:
  HarvestRetirementTest() : state_(0, 0, 0, 0), harvest_() {}

 protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(10, 60, 20, 140);
    harvest_ = std::make_unique<healthcare::HarvestRetirement>(7, 0.6);
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestRetirement> harvest_;
};

TEST_F(HarvestRetirementTest, GetHarvest) {
  ASSERT_EQ(12, harvest_->GetHarvest(state_));
}

TEST_F(HarvestRetirementTest, GetWorkingHarvest) {
  ASSERT_EQ(0, harvest_->GetWorkingHarvest(state_));
}
