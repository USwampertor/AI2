#include "UnitType.h"
#include "sqlite3.h"

int
mountData(void* data, int count, char** fields, char** values) {

  UnitType* p = (UnitType*)data;



  return 0;
}

void
UnitType::loadFromDb(const int id) {
  sqlite3 *db;
  std::string errorCatcher;
  errorCatcher.resize(128);
  std::stringstream sqlCommand;

  sqlCommand << "select * from UnitType where ID = " << id << ";";
  std::string sqlStream = sqlCommand.str();
  int p = sqlite3_open("resources/databases/DungeonCrawler.db", &db);
  p = sqlite3_exec(db, sqlStream.c_str(), mountData, this, (char**)&errorCatcher[0]);
}
