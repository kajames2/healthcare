#include <gtest/gtest.h>

#include <memory>

#include "healthcare/harvest_linear.h"

class HarvestLinearTest : public ::testing::Test {
 public:
  HarvestLinearTest() : harvest_() {}

 protected:
  virtual void SetUp() {
    harvest_ = std::make_unique<healthcare::HarvestLinear>(0.75);
  }

  std::unique_ptr<healthcare::HarvestLinear> harvest_;
};

TEST_F(HarvestLinearTest, GetHarvest) {
  ASSERT_DOUBLE_EQ(45, harvest_->GetHarvest(1, 60));
  ASSERT_DOUBLE_EQ(45, harvest_->GetHarvest(10, 60));
}
