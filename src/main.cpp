#include <iostream>
#include <memory>

#include "DBInterface.h"
#include "SQLiteInterface.h"

int main(int argc, char **argv) {
  std::unique_ptr<DBInterface> db = std::make_unique<SQLiteInterface>();
  std::cout << std::boolalpha << "DB opened: " << db->open("test.db") << "\n";
  std::cout << std::boolalpha << "DB closed: " << db->close() << "\n";
}
