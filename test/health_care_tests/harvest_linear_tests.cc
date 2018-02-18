#include "harvest_linear.h"
#include "health_state.h"
#include <gtest/gtest.h>

#include <memory>

class HarvestLinearTest : public ::testing::Test {
public:
  HarvestLinearTest()
      : state_(0, 0, 0, 0)
      , harvest_() {}

protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(1, 60, 20, 0);
    harvest_ = std::make_unique<healthcare::HarvestLinear>(0.75);
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestLinear> harvest_;
};

TEST_F(HarvestLinearTest, GetHarvest) {
  ASSERT_DOUBLE_EQ(45, harvest_->GetHarvest(state_));
  state_.period = 10;
  ASSERT_DOUBLE_EQ(45, harvest_->GetHarvest(state_));
}
