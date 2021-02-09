#include <Utils.h>
#include <cctype>

namespace utils {

std::string &rtrim(std::string &ins, const std::string &pattern) {
  while (!ins.empty()) {
    if (pattern.find(ins.back())) {
      ins.pop_back();
    } else {
      break;
    }
  }
  return ins;
}

std::string &ltrim(std::string &ins, const std::string &pattern) {
  ins.reserve();
  rtrim(ins, pattern);
  ins.reserve();
  return ins;
}

std::string &trim(std::string &ins, const std::string &pattern) {
  ltrim(ins, pattern);
  rtrim(ins, pattern);
  return ins;
}

std::string lstrip(const std::string &ins, const std::string &pattern) {
  auto res = ins;
  return ltrim(res, pattern);
}
std::string rstrip(const std::string &ins, const std::string &pattern) {
  auto res = ins;
  return rtrim(res, pattern);
}
std::string strip(const std::string &ins, const std::string &pattern) {
  auto res = ins;
  return trim(res, pattern);
}

std::string &be_lower(std::string &in_out) {
  for (auto &c : in_out) {
    c = tolower(c);
  }
  return in_out;
}
std::string &be_upper(std::string &in_out) {
  for (auto &c : in_out) {
    c = toupper(c);
  }
  return in_out;
}

std::string to_lower(const std::string &ins) {
  auto res = ins;
  return be_lower(res);
}
std::string to_upper(const std::string &ins) {
  auto res = ins;
  return be_upper(res);
}

} // namespace utils
