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
  ConfigParser(const std::string& path) : m_path(path) {
    load();
  }

  void load();
  void list_keys();
  void list_keys_with_values();

 private:
  std::string trim_whitespace(const std::string& s);

  std::string m_path;
  std::unordered_map<std::string, std::string> m_cfg;

};

} // namespace wrx_checker