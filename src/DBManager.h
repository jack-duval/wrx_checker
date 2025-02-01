//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <sqlite3.h>
#include "events/Event.h"
#include "faults/Fault.h"

namespace wrx_checker {

class DBManager {
 public:
  explicit DBManager(const std::string& name);
  ~DBManager();

  void add_fault(Event& event);
  void add_event(Fault& fault);

  void clear_table(const std::string& table_name);
  void execute_query(const std::string& query);

  void open();
  void close();

 private:
  sqlite3* m_db;
  std::string m_name;
  void get_columns(const std::string& table, std::vector<std::string>& columns);
};

} // namespace wrx_checker