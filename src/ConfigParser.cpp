//
// Created by Jack Duval on 1/29/25.
//

#include "ConfigParser.h"

namespace wrx_checker {

void ConfigParser::load_cfg() {

}

std::string ConfigParser::trim_whitespace(const std::string &s) {
  size_t start = s.find_first_not_of(" \t");
  if (start == std::string::npos) return "";

  size_t end = s.find_last_not_of(" \t");
  return s.substr(start, end-start + 1);
}

void ConfigParser::load() {
  std::ifstream f(m_path);

  if (!f) {
    std::cerr << "Could not open file: " << m_path << std::endl;
    return;
  }


}


} // namespace wrx_checker