#include "DBInterface.h"

bool DBInterface::open(std::string dbName) {
  sqlite3* tmpDB = nullptr;
  int rc = sqlite3_open(dbName.c_str(), &tmpDB);
  if (rc != SQLITE_OK) {
    return false;
  }
  _db = std::unique_ptr<sqlite3, sqlite3deleter>(tmpDB);
  return true;
}

bool DBInterface::close() {
  if (_db) {
    sqlite3_close(_db.get());
    return true;
  }
  return false;
}
