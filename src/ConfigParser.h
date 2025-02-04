//
// Created by Jack Duval on 1/29/25.
//
#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>

namespace wrx_checker {

class ConfigParser {
 public:
  ConfigParser();

  // in case we want to load other cfg files later?
  explicit ConfigParser(const std::string& path) : m_path(path) {
    if (bool load_result = load()) {
      return;
    } else {
      std::cerr << "Could not load cfg" << std::endl;
    }
  }

  bool load();
  std::string get_val(const std::string& key) { return m_cfg[key]; }
  void list_keys();
  void list_keys_with_values();
  std::pair<std::string, std::string> parse_line(const std::string& line);

 private:
  std::string trim_whitespace(const std::string& s);

  std::string m_path;
  std::unordered_map<std::string, std::string> m_cfg;

};

} // namespace wrx_checker