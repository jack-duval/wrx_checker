//
// Created by Jack Duval on 1/25/25.
//

#include "DBManager.h"
namespace wrx_checker {

DBManager::DBManager(const std::string &name) {
  int response = sqlite3_open(name.c_str(), &db);
  if (response) {
    std::cerr << "Cannot open sqlite database: " << sqlite3_errmsg(db) << std::endl;
  } else {
    std::cout << "Successfully opened DB" << std::endl;
  }
}

DBManager::~DBManager() {
  if (db) {
    sqlite3_close(db);
    std::cout << "Closed database" << std::endl;
  }
}

void DBManager::clear_table(const std::string &table_name) {
  std::vector<std::string> columns;
  get_columns(table_name, columns);

  std::stringstream updateQuery;
  updateQuery << "UPDATE " << table_name << " SET ";

  for (size_t i = 0; i < columns.size(); ++i) {
    updateQuery << columns[i] << " = NULL";
    if (i < columns.size() -1) {
      updateQuery << ", ";
    }
  }

  updateQuery << ";";
  execute_query(updateQuery.str());
}

void DBManager::execute_query(const std::string &query) {
  char* err = nullptr;
  int result = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &err);
  if (result != SQLITE_OK) {
    std::cerr << "SQL ERROR: " << err << std::endl;
  } else {
    std::cout << "Query executed: " << query << std::endl;
  }
}

void DBManager::get_columns(const std::string &table,
                            std::vector<std::string> &columns) {
  std::stringstream query;
  query << "PRAGMA table_info(" << table << ");";

  sqlite3_stmt* stmt;
  int response = sqlite3_prepare_v2(db, query.str().c_str(), -1, &stmt, 0);

  if (response != SQLITE_OK) {
    std::cerr << "Failed to fetch columns for table: " << table << ": " << sqlite3_errmsg(db) << std::endl;
    return;
  }

  while ((response = sqlite3_step(stmt)) == SQLITE_ROW) {
    std::string column = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    columns.push_back(column);
  }

  sqlite3_finalize(stmt);
}

}