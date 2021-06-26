#ifndef SQLITEINTERFACE_H
#define SQLITEINTERFACE_H

#include "DBInterface.h"

class SQLiteInterface : public DBInterface {
public:
  ~SQLiteInterface();
  bool open(std::string dbName) override;
  bool close() override;
  int32_t itemCount() const override;
  int32_t addItem(std::string itemText) override;
  int32_t setItemComplete(int32_t ID, bool complete) override;

private:
  struct sqlite3deleter {
    void operator()(sqlite3 *db) { sqlite3_close(db); }
  };
  std::unique_ptr<sqlite3, sqlite3deleter> _db = nullptr;
  bool createTable();
};

#endif // SQLITEINTERFACE_H
