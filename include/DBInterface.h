#pragma once

#include <memory>
#include <sqlite3.h>
#include <string>

class DBInterface {
public:
  virtual bool open(std::string dbName) = 0;
  virtual bool close() = 0;
  virtual ~DBInterface() {}

  virtual int32_t itemCount() const = 0;
  virtual int32_t addItem(std::string itemText) = 0;
  virtual int32_t setItemComplete(int32_t ID, bool complete) = 0;

private:
};
