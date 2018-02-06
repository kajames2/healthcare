#include "harvest_composite.h"
#include "harvest_linear.h"
#include "harvest_retirement.h"
#include "health_state.h"
#include <gtest/gtest.h>

#include <vector>
#include <memory>

class HarvestCompositeTest : public ::testing::Test {
public:
  HarvestCompositeTest()
      : state_(0,0,0,0)
      , harvest_(std::make_shared<healthcare::HarvestComposite>()) {}

protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(1, 60, 20, 140);
    harvest1_ = std::make_shared<healthcare::HarvestLinear>(1, 5, 1);
    harvest2_ = std::make_shared<healthcare::HarvestRetirement>(8, 0.5);
    harvest_->AddHarvest(harvest1_);
    harvest_->AddHarvest(harvest2_);
  }

  healthcare::HealthState state_;
  std::shared_ptr<healthcare::HarvestLinear> harvest1_;
  std::shared_ptr<healthcare::HarvestRetirement> harvest2_;
  std::shared_ptr<healthcare::HarvestComposite> harvest_;
};

TEST_F(HarvestCompositeTest, GetHarvest) {
  ASSERT_EQ(60, harvest_->GetHarvest(state_));
  state_.period = 7;
  ASSERT_EQ(0, harvest_->GetHarvest(state_));
  state_.period = 10;
  ASSERT_EQ(10, harvest_->GetHarvest(state_));
}

TEST_F(HarvestCompositeTest, GetWorkingHarvest) {
  ASSERT_EQ(60, harvest_->GetWorkingHarvest(state_));
  state_.period = 7;
  ASSERT_EQ(0, harvest_->GetWorkingHarvest(state_));
  state_.period = 10;
  ASSERT_EQ(0, harvest_->GetWorkingHarvest(state_));
}


TEST_F(HarvestCompositeTest, InRange) {
  ASSERT_TRUE(harvest_->InRange(1));
  ASSERT_FALSE(harvest_->InRange(7));
  ASSERT_TRUE(harvest_->InRange(8));
}
