#include <iostream>
#include "DBManager.h"
#include "CSVParser.h"
#include "events/ACCompressorStatusChange.h"

int main() {
//  wrx_checker::DBManager db_manager;
////  db_manager.clear_table("events");
////  db_manager.clear_table("faults");
//  db_manager.execute_query("SELECT * FROM events");
//
  wrx_checker::CSVParser csv = wrx_checker::CSVParser();
  csv.load();



  return 0;
}
