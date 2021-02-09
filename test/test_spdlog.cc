#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

TEST(TestSPDLOG, log_one) {
  spdlog::info("hello spdlog");
  ASSERT_TRUE(true);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
