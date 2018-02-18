#include "harvest_retirement.h"
#include "health_state.h"
#include <gtest/gtest.h>

#include <memory>

class HarvestRetirementTest : public ::testing::Test {
public:
  HarvestRetirementTest()
      : state_(0,0,0,0)
      , harvest_() {}

protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(1, 60, 20, 140);
    harvest_ = std::make_unique<healthcare::HarvestRetirement>(8, 0.6);
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestRetirement> harvest_;
};

TEST_F(HarvestRetirementTest, GetHarvest) {
  ASSERT_EQ(0, harvest_->GetHarvest(state_));
  state_.period = 10;
  ASSERT_EQ(12, harvest_->GetHarvest(state_));
}

TEST_F(HarvestRetirementTest, GetWorkingHarvest) {
  ASSERT_EQ(0, harvest_->GetWorkingHarvest(state_));
  state_.period = 10;
  ASSERT_EQ(0, harvest_->GetWorkingHarvest(state_));
}

TEST_F(HarvestRetirementTest, InRange) {
  ASSERT_FALSE(harvest_->InRange(1));
  ASSERT_TRUE(harvest_->InRange(8));
}