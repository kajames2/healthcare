#include "harvest_flat.h"
#include "health_state.h"
#include <gtest/gtest.h>

#include <memory>

class HarvestFlatTest : public ::testing::Test {
public:
  HarvestFlatTest() : state_(0, 0, 0, 0), harvest_() {}

protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(1, 60, 20, 0);
    harvest_ = std::make_unique<healthcare::HarvestFlat>(1, 5, 85);
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestFlat> harvest_;
};

TEST_F(HarvestFlatTest, GetHarvest) {
  ASSERT_DOUBLE_EQ(85, harvest_->GetHarvest(state_));
  state_.period = 10;
  ASSERT_DOUBLE_EQ(0, harvest_->GetHarvest(state_));
}

TEST_F(HarvestFlatTest, InRange) {
  ASSERT_TRUE(harvest_->InRange(1));
  ASSERT_TRUE(harvest_->InRange(5));
  ASSERT_TRUE(harvest_->InRange(3));
  ASSERT_FALSE(harvest_->InRange(7));
  ASSERT_FALSE(harvest_->InRange(-1));
}
