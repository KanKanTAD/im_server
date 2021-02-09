#include "Configure.h"
#include "Utils.h"

namespace myim {
const static std::string kDes_type{"type"};
const static std::string kDes_username{"username"};
const static std::string kDes_password{"password"};
const static std::string kDes_url{"url"};
const static std::string kDes_filepath{"filepath"};

DBTYPE DB_Config::parse_dbtype(const std::string &ins) {
  auto db = utils::to_lower(utils::strip(ins));
  if (db == "mysql") {
    return DBTYPE::kMysql;
  } else if (db == "sqlite" || db == "sqlite3") {
    return DBTYPE::kSqlite;
  }
  return DBTYPE::kUnkown;
}

void DB_Config::load(const std::string &file_path, DB_Config &out_arg) {}

DB_Config::DB_Config()
    : type(DBTYPE::kUnkown), url(""), username(""), password(""), filepath("") {
}
DB_Config::~DB_Config() {}
} // namespace myim
