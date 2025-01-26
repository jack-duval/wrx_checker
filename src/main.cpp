#include <iostream>
#include "DBManager.h"

int main() {
  wrx_checker::DBManager db_manager("db/wrx_checker.sqlite");
//  db_manager.clear_table("events");
//  db_manager.clear_table("faults");
  db_manager.execute_query("SELECT * FROM events");
  return 0;
}