#include "healthcare/harvest_flat.h"

#include <memory>

#include <gtest/gtest.h>

#include "healthcare/health_state.h"

class HarvestFlatTest : public ::testing::Test {
 public:
  HarvestFlatTest() : state_(0, 0, 0, 0), harvest_() {}

 protected:
  virtual void SetUp() {
    state_ = healthcare::HealthState(1, 60, 20, 0);
    harvest_ = std::make_unique<healthcare::HarvestFlat>(85);
  }

  healthcare::HealthState state_;
  std::unique_ptr<healthcare::HarvestFlat> harvest_;
};

TEST_F(HarvestFlatTest, GetHarvest) {
  ASSERT_DOUBLE_EQ(85, harvest_->GetHarvest(state_));
  state_.period = 10;
  ASSERT_DOUBLE_EQ(85, harvest_->GetHarvest(state_));
}
