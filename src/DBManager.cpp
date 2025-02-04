//
// Created by Jack Duval on 1/25/25.
//

#include "DBManager.h"
namespace wrx_checker {

DBManager::DBManager(const std::string &name) {
  std::cout << "Using name: " << name << std::endl;

  if (name == "") {
    std::cout << "Using default name and config parser" << std::endl;
    m_cfg = std::make_unique<ConfigParser>();
    // m_name = m_cfg->get_val("db_path");
    m_name = "/home/jd/Desktop/wrx_checker/wrx_checker.sqlite";
    std::cout << m_name << std::endl;
  }


}

DBManager::~DBManager() {
  if (m_db) {
    sqlite3_close(m_db);
    std::cout << "Closed database" << std::endl;
  }
}

void DBManager::open() {
  if (m_db) {
    return;
  } else {
    if (int response = sqlite3_open(m_name.c_str(), &m_db)) {
      std::cerr << "Cannot open sqlite m_db: " << sqlite3_errmsg(m_db) << std::endl;
    } else {
      std::cout << "Successfully Opened DB" << std::endl;
    }
  }
}

void DBManager::close() const {
  if (m_db) {
    sqlite3_close(m_db);
  }

  return;
}

void DBManager::add_event(const Event& event) {
  if (!m_db) {
    open();
  }

  std::string query = "INSERT INTO events VALUES (";
  query.append(event.getType());
  query.append(", ");
  query.append(std::to_string(event.getTime()));
  query.append(", ");
  query.append(event.serializeToProto());
  query.append(")");
  execute_query(query);

  close();
}

void DBManager::add_fault(Fault& fault) {
  if (!m_db) {
    open();
  }

  std::string query = "INSERT INTO faults VALUES (";
  query.append(fault.getType());
  query.append(", ");
  query.append(std::to_string(fault.getTime()));
  query.append(", ");
  query.append(fault.getSeverity());
  query.append(", ");
  query.append(fault.serializeToProto());
  query.append(")");
  execute_query(query);

  close();
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
  open();
  char* err = nullptr;
  int result = sqlite3_exec(m_db, query.c_str(), nullptr, nullptr, &err);
  if (result != SQLITE_OK) {
    std::cerr << "SQL ERROR: " << err << std::endl;
  } else {
    std::cout << "Query executed: " << query << std::endl;
  }
  close();
}

void DBManager::get_columns(const std::string &table,
                            std::vector<std::string> &columns) {
  std::stringstream query;
  query << "PRAGMA table_info(" << table << ");";

  if (!m_db) { open(); }

  sqlite3_stmt* stmt;
  int response = sqlite3_prepare_v2(m_db, query.str().c_str(), -1, &stmt, 0);

  if (response != SQLITE_OK) {
    std::cerr << "Failed to fetch columns for table: " << table << ": " << sqlite3_errmsg(m_db) << std::endl;
    return;
  }

  while ((response = sqlite3_step(stmt)) == SQLITE_ROW) {
    std::string column = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    columns.push_back(column);
  }

  sqlite3_finalize(stmt);
}

}