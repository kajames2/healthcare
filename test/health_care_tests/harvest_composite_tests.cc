#include "harvest_composite.h"
#include "harvest_linear.h"
#include "harvest_retirement.h"
#include "health_state.h"
#include "period_range.h"
#include <gtest/gtest.h>

#include <iostream>
#include <memory>

class HarvestCompositeTest : public ::testing::Test {
public:
  HarvestCompositeTest()
      : state_(0, 0, 0, 0),
        harvest_(std::make_unique<healthcare::HarvestComposite>()) {}

protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(2, 60, 20, 140);
    harvest1_ = std::make_unique<healthcare::HarvestLinear>(1);
    harvest2_ = std::make_unique<healthcare::HarvestRetirement>(7, 0.5);
    harvest_->AddHarvest(healthcare::PeriodRange{1, 5}, std::move(harvest1_));
    harvest_->AddHarvest(healthcare::PeriodRange{9, 100}, std::move(harvest2_));
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestLinear> harvest1_;
  std::unique_ptr<healthcare::HarvestRetirement> harvest2_;
  std::unique_ptr<healthcare::HarvestComposite> harvest_;
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
