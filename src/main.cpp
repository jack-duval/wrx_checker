#include <iostream>
#include "DBManager.h"
#include "CSVParser.h"

int main() {
//  wrx_checker::DBManager db_manager("db/wrx_checker.sqlite");
//  db_manager.clear_table("events");
//  db_manager.clear_table("faults");
//  db_manager.execute_query("SELECT * FROM events");

  wrx_checker::CSVParser csv = wrx_checker::CSVParser();
  csv.load();
  csv.print();

  return 0;
}