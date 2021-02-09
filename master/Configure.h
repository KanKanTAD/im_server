#pragma once
#include <string>

enum DBTYPE { kSqlite, kMysql, kUnkown };

struct DB_Config {
  static DBTYPE parse_dbtype(const std::string &);
  static void load(const std::string &, DB_Config &);
  DBTYPE type;
  std::string url;
  std::string username;
  std::string password;
  std::string filepath;
};
