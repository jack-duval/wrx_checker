//
// Created by Jack Duval on 1/25/25.
//
#pragma once

#import "DBManager.h"

namespace wrx_checker {

class FaultReporter {
 public:
  FaultReporter(DBManager& db_manager): m_db_manager(db_manager) {}

  void report_fault();

 private:
  DBManager& m_db_manager;

};

} // wrx_checker

