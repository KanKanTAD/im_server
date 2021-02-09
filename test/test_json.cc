#include <exception>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <sstream>

const static char *config_path =
    "/home/v_fantnzeng/Public/linux_study/im_server/config/db_config.json";

TEST(TestJSON, non) {
  std::ifstream ifs;
  ifs.open(config_path);
  ASSERT_TRUE(ifs.is_open());
  nlohmann::json j;
  ifs >> j;
  ifs.close();
  ASSERT_EQ(j["type"], "sqlite3");
}

TEST(TestJSON, find_none) {
  std::ifstream ifs(config_path);
  ASSERT_TRUE(ifs.is_open());
  nlohmann::json j;
  ifs >> j;
  ifs.close();
  auto user_it = j.find("username");
  ASSERT_FALSE(user_it == j.end());

  ASSERT_EQ(user_it->get<std::string>(), "none");
  std::cout << user_it->get<std::string>() << std::endl;

  auto non_it = j.find("kkkkkk");
  ASSERT_TRUE(non_it == j.end());
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
