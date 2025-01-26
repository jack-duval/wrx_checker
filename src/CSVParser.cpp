//
// Created by Jack Duval on 1/25/25.
//

#include "CSVParser.h"

namespace wrx_checker {

bool CSVParser::load() {
  std::ifstream file(m_path);
  if (!file.is_open()) {
    std::cerr << "Could not open the CSV File at " << m_path << "..." << std::endl;
    return false;
  }

  m_data.clear();
  std::string l;
  bool is_header = true;
  while (std::getline(file, l)) {
    if (is_header) {
      is_header = false;
      continue;
    }

    if (!l.empty()) {
      m_data.emplace_back(parse_line(l));
    }
    counter++;
  }
  return true;
}

std::vector<std::string> CSVParser::parse_line(const std::string &l) {
  std::vector<std::string> fields;
  std::string val;
  bool in_quotes = false;

  for (char c : l) {
    if (c == '"' && (val.empty() || val.back() != '\\')) {
      in_quotes = true;
    } else if (c == m_delimiter[0] && in_quotes) {
      fields.push_back(trim(remove_quotes(val)));
      val.clear();
    } else {
      val += c;
    }
  }

  if (!val.empty()) {
    fields.push_back(trim(remove_quotes(val)));
  }

  return fields;
}

void CSVParser::print() {
  for (const auto& row : m_data) {
    for (size_t i = 0; i < row.size(); ++i) {
      std::cout << row[i];
      if (i < row.size() -1) std::cout << m_delimiter;
    }
    std::cout << std::endl;
  }
}

} // namespace wrx_checker