#include "UnitType.h"
//#include "sqlite3.h"

int
mountData(void* data, int count, char** value, char** columns) {

  UnitType* p = (UnitType*)data;

  p->m_typeID = (unsigned int)value[0];
  p->m_name = value[1];
  p->m_hp = atoi(value[2]);
  p->m_speed = atoi(value[3]);
  p->m_strength = atoi(value[4]);
  p->m_defense = atoi(value[5]);
  return 0;
}

void
UnitType::loadFromDb(const int id) {
  sqlite3* db;
  std::string errorCatcher;
  errorCatcher.resize(128);
  std::stringstream sqlCommand;

  sqlCommand << "select * from UnitType where ID = " << id << ";";
  std::string sqlStream = sqlCommand.str();
  int p = sqlite3_open("resources/databases/DungeonCrawler.db", &db);
  if (p) {
    std::cout << (stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return;
  }

  p = sqlite3_exec(db, sqlStream.c_str(), mountData, this, (char**)&errorCatcher[0]);
  if (p != SQLITE_OK) {
    std::cout << (stderr, "SQL error: %s\n", errorCatcher);
    sqlite3_free(db);
  }


  sqlite3_close(db);
}
