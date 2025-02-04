//
// Created by Jack Duval on 1/29/25.
//

#include "ConfigParser.h"

namespace wrx_checker {

ConfigParser::ConfigParser() {
  m_path = "/Users/jack/Desktop/Development/wrx_checker/src/project.cfg";
  bool load_result = load();
  if (load_result) {
    return;
  } else {
    std::cerr << "Could not load cfg" << std::endl;
  }
}

bool ConfigParser::load() {
  std::ifstream file(m_path);
  if (!file.is_open()) {
    std::cerr << "Could not open the project.cfg file at " << m_path << "." << std::endl;
    return false;
  }

  m_cfg.clear();
  std::string l;
  while (std::getline(file, l)) {
    if (!l.empty()) {
      std::pair<std::string, std::string> parsed_line = parse_line(l);
      m_cfg[parsed_line.first] = parsed_line.second;
    }
  }

  return true;
}

std::pair<std::string, std::string> ConfigParser::parse_line(const std::string &l) {
  bool in_quotes = false;
  size_t eq = 0;

  for (size_t i = 0; i < l.size(); ++i) {
    if (l[i] == '=') {
      eq = i;
    }
  }

  if (l[eq+1] && l[eq+1] == '"') {
    in_quotes = true;
  }

  std::string key = l.substr(0, eq);
  std::cout << key << std::endl;

  std::string val;

  if (in_quotes) {
    val = l.substr(eq+2, l.size() - (3 + eq));
  } else {
     val = l.substr(eq+1, l.size() - (1 + eq));
  }

  return std::pair<std::string, std::string>(trim_whitespace(key),
                                             trim_whitespace(val));
}

std::string ConfigParser::trim_whitespace(const std::string &s) {
  size_t start = s.find_first_not_of(" \t");
  if (start == std::string::npos) return "";

  size_t end = s.find_last_not_of(" \t");
  return s.substr(start, end-start + 1);
}

void ConfigParser::list_keys() { return; }
void ConfigParser::list_keys_with_values() { return; }


} // namespace wrx_checker