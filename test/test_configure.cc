#include "Configure.h"
#include <gtest/gtest.h>

TEST(TestConfigure, parse_dbtype) {
  auto db_type = myim::DB_Config::parse_dbtype("sqlite3");
  ASSERT_EQ(db_type, myim::DBTYPE::kSqlite);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
