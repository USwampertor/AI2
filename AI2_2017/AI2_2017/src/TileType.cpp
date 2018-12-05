/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file TileType.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/04 2018
 * @brief member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "TileType.h"

int
mountTile(void* data, int count, char** value, char** columns) {

  TileType* p = (TileType*)data;

  p->m_typeID = atoi(value[0]);
  p->m_name = value[1];
  p->m_resource = value[2];
  std::string temp = value[3];

  std::istringstream buffer(temp);
  buffer >> p->m_rectangle.position.x;
  buffer >> p->m_rectangle.position.y;
  buffer >> p->m_rectangle.size.x;
  buffer >> p->m_rectangle.size.y;

  return 0;
}

void
TileType::loadFromDb(const int id) {
  sqlite3* db;
  std::string errorCatcher;
  errorCatcher.resize(128);
  std::stringstream sqlCommand;

  sqlCommand << "select * from TileType where ID = " << id << ";";
  std::string sqlStream = sqlCommand.str();
  int p = sqlite3_open("resources/databases/DungeonCrawler.db", &db);
  if (p) {
    std::cout << (stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return;
  }

  p = sqlite3_exec(db, sqlStream.c_str(), mountTile, this, (char**)&errorCatcher[0]);
  if (p != SQLITE_OK) {
    std::cout << (stderr, "SQL error: %s\n", errorCatcher);
    sqlite3_free(db);
  }

  sqlite3_close(db);
}
