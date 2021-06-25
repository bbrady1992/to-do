#include <iostream>

#include "DBInterface.h"

int main(int argc, char** argv) {
  auto db = DBInterface{};
  std::cout << std::boolalpha << "DB opened: " << db.open("test.db") << "\n";
  std::cout << std::boolalpha << "DB closed: " << db.close() << "\n";
}
