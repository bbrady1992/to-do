#include "SQLiteInterface.h"

SQLiteInterface::~SQLiteInterface() {}

bool SQLiteInterface::open(std::string dbName) {
  sqlite3 *tmpDB = nullptr;
  int rc = sqlite3_open(dbName.c_str(), &tmpDB);
  if (rc != SQLITE_OK) {
    return false;
  }
  _db = std::unique_ptr<sqlite3, sqlite3deleter>(tmpDB);

  return createTable();
}

bool SQLiteInterface::close() {
  if (_db) {
    sqlite3_close(_db.get());
    return true;
  }
  return false;
}

int32_t SQLiteInterface::itemCount() const { return -1; }

int32_t SQLiteInterface::addItem(std::string itemText) { return -1; }

int32_t SQLiteInterface::setItemComplete(int32_t ID, bool complete) {
  return -1;
}

bool SQLiteInterface::createTable() {
  sqlite3_stmt *stmt;
  std::string q = "create table if not exists items('ID' integer primary key "
                  "autoincrement, 'text' text, 'date' date);";
  bool rc = sqlite3_prepare_v2(_db.get(), q.c_str(), -1, &stmt, nullptr);
  sqlite3_step(stmt);
  sqlite3_finalize(stmt);
  return rc == SQLITE_OK;
}
