#include "Utils.h"
#include <gtest/gtest.h>
#include <spdlog/spdlog.h>

TEST(TestUtils, ltrim) {
  std::string s{"   hello ltrim "};
  auto si = utils::ltrim(s);
  spdlog::info("si:[{0}] | s:[{1}]", si, s);
  ASSERT_EQ(s, "hello ltrim ");
}

TEST(TestUtils, trim) {
  std::string s{" hello trim 	"};
  auto si = utils::trim(s);
  spdlog::info("si:[{0}] | s:[{1}]", si, s);
  ASSERT_EQ(s, "hello trim");
}

TEST(TestUtils, to_upper) {
  std::string s{"MySql"};
  auto si = utils::to_upper(s);
  spdlog::info("si:[{0}] | s:[{1}]", si, s);
  ASSERT_EQ(si, "MYSQL");
}

TEST(TestUtils, to_lower) {
  std::string s{"MySql"};
  auto si = utils::to_lower(s);
  spdlog::info("si:[{0}] | s:[{1}]", si, s);
  ASSERT_EQ(si, "mysql");
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
