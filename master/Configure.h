#pragma once

#include <string>

namespace myim {

enum DBTYPE { kSqlite, kMysql, kUnkown };

struct DB_Config {
  DB_Config();
  virtual ~DB_Config();
  static DBTYPE parse_dbtype(const std::string &);
  static void load(const std::string &, DB_Config &);
  // fields
  DBTYPE type;
  std::string url;
  std::string username;
  std::string password;
  std::string filepath;
};

} // namespace myim
