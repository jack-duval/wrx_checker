#include <iostream>

#include "Analyzer.h"
#include "DBManager.h"
#include "CSVParser.h"
#include "sqlite3.h"
#include "events/ACCompressorStatusChange.h"

int main() {
  // wrx_checker::DBManager db_manager;
  // // db_manager.clear_table("events");
  // // db_manager.clear_table("faults");
  // db_manager.execute_query("SELECT * FROM events");
  // std::shared_ptr<wrx_checker::DBManager> db_manager = std::make_shared<wrx_checker::DBManager>("/home/jd/Desktop/wrx_checker/wrx_checker.sqlite");

  wrx_checker::ACCompressorStatusChange test_event(1.5, false);

  std::string id = "2";
  std::string t = std::to_string(test_event.getTime());
  std::string type = test_event.getType();
  std::string proto_data = test_event.serializeToProto();

  const char *sql = ("INSERT INTO events (" + id + ", " + type + ", " + t + ", " + proto_data + ")").c_str();

  sqlite3* db;
  int rc;

  rc = sqlite3_open("/home/jd/Desktop/wrx_checker/wrx_checker.sqlite", &db);
  if (rc) {
    std::cerr << "Can't open DB" << sqlite3_errmsg(db) << std::endl;
    return 1;
  }

  char* zErrMsg = 0;
  rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    std::cerr << "SQL Err: " << zErrMsg << std::endl;
    sqlite3_free(zErrMsg);
  }

  sqlite3_close(db);
  return 0;


  // db_manager.add_event(test_event);

  // wrx_checker::CSVParser csv = wrx_checker::CSVParser();
  // csv.load();
  // csv.print();

  // wrx_checker::Analyzer analyzer(csv.get_data());

  return 0;
}
