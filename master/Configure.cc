#include "Configure.h"
#include <Utils.h>
#include <cassert>
#include <fmt/format.h>
#include <fstream>
#include <nlohmann/json.hpp>
#include <spdlog/fmt/bundled/core.h>
#include <spdlog/spdlog.h>
#include <stdexcept>

const static std::string kDes_type{"type"};
const static std::string kDes_username{"username"};
const static std::string kDes_password{"password"};
const static std::string kDes_url{"url"};
const static std::string kDes_filepath{"filepath"};

DBTYPE DB_Config::parse_dbtype(const std::string &ins) {
  std::string i = utils::strip(ins);
  utils::be_lower(i);
  if (i == "mysql") {
    return DBTYPE::kMysql;
  } else if (i == "sqlite3" || i == "sqlite") {
    return DBTYPE::kSqlite;
  }
  return DBTYPE::kUnkown;
}

void DB_Config::load(const std::string &file_path, DB_Config &out_arg) {
  spdlog::debug("parse config [{0}]", file_path);
  std::ifstream ifs(file_path);
  if (!ifs.is_open()) {
    auto msg_ = fmt::format("file_path[{0}] can not be open!", file_path);
    spdlog::error(msg_);
    throw std::runtime_error(msg_);
    return;
  }
  nlohmann::json json_;
  ifs >> json_;
  ifs.close();
  auto type_it = json_.find(kDes_type);
  out_arg.type = type_it == json_.end()
                     ? DBTYPE::kSqlite
                     : parse_dbtype(type_it->get<std::string>());
  auto url_it = json_.find(kDes_url);
  out_arg.url =
      url_it == json_.end() ? "" : utils::strip(url_it->get<std::string>());

  auto name_it = json_.find(kDes_username);
  out_arg.username = name_it == json_.end()
                         ? "root"
                         : utils::strip(name_it->get<std::string>());

  auto pass_it = json_.find(kDes_password);
  out_arg.password = pass_it == json_.end()
                         ? "123456"
                         : utils::strip(pass_it->get<std::string>());

  auto file_it = json_.find(kDes_filepath);
  out_arg.filepath =
      file_it == json_.end() ? "" : utils::strip(file_it->get<std::string>());
}
