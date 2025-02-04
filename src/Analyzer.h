//
// Created by Jack Duval on 2/1/25.
//
#pragma once

#include "CSVParser.h"

namespace wrx_checker {

class Analyzer {
 public:
  Analyzer(std::vector<RowContext>& data) : m_data(data) {}

 private:
  std::vector<RowContext> m_data;

};

} // namespace wrx_checker