//
// Created by Jack Duval on 1/25/25.
//

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <string_view>
#include <iostream>

namespace wrx_checker {

class CSVPreProcessor {

};

class CSVParser {
 public:
  explicit CSVParser(const std::string& delim = ",", const std::string& path = "/Users/jack/Desktop/Development/wrx_checker/data/datalog1.csv")
    : m_delimiter(delim), m_path(path) {}

  bool load();
  [[nodiscard]] const std::vector<std::vector<std::string>>& get_data() const {
    return m_data;
  }

  void print();



 protected:
  std::vector<std::vector<std::string>> m_data;
  std::string m_path;
  std::string m_delimiter;

 private:
  // somethigng to extract vals from fields.
  std::vector<std::string> parse_line(const std::string& l);

  // Removes surrounding quotes from a string
  static std::string remove_quotes(const std::string& str) {
    if (str.size() >= 2 && str.front() == '"' && str.back() == '"') {
      return str.substr(1, str.size() - 2);
    }
    return str;
  }

  // Trims whitespace from the beginning and end of a string
  static std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
  }

};

} // namespace wrx_checker