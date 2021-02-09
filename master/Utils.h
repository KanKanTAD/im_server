#pragma once

#include <string>
namespace utils {

inline std::string &ltrim(std::string &,
                          const std::string &pattern = "\n\r\t ");
inline std::string &rtrim(std::string &,
                          const std::string &pattern = "\n\r\t ");
inline std::string &trim(std::string &, const std::string &pattern = "\n\r\t ");
inline std::string lstrip(const std::string &,
                          const std::string &pattern = "\n\r\t ");
inline std::string rstrip(const std::string &,
                          const std::string &pattern = "\n\r\t ");
inline std::string strip(const std::string &,
                         const std::string &pattern = "\n\r\t ");

inline std::string& be_lower(std::string &);
inline std::string to_lower(const std::string &);
inline std::string& be_upper(std::string &);
inline std::string to_upper(const std::string &);

} // namespace utils
