#include <memory>
#include <sqlite3.h>
#include <string>

class DBInterface {
  public:
    bool open(std::string dbName);
    bool close();

  private:
    struct sqlite3deleter {
      void operator()(sqlite3* db) {
        sqlite3_close(db);
      }
    };
    std::unique_ptr<sqlite3, sqlite3deleter> _db = nullptr;
};
