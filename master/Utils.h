#pragma once

#include <string>
namespace utils {

std::string &ltrim(std::string &, const std::string &pattern = "\n\r\t ");
std::string &rtrim(std::string &, const std::string &pattern = "\n\r\t ");
std::string &trim(std::string &, const std::string &pattern = "\n\r\t ");
std::string lstrip(const std::string &, const std::string &pattern = "\n\r\t ");
std::string rstrip(const std::string &, const std::string &pattern = "\n\r\t ");
std::string strip(const std::string &, const std::string &pattern = "\n\r\t ");

std::string &be_lower(std::string &);
std::string to_lower(const std::string &);
std::string &be_upper(std::string &);
std::string to_upper(const std::string &);

} // namespace utils
