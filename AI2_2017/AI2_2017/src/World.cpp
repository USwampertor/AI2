#include "World.h"


void
World::initialization() {
  sqlite3* db;
  std::string errorString;

  errorString.resize(128);
  
  
  /*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
  /**
   * World.cpp loading of unitTypes
   */
  /*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
  std::stringstream sqlCommand;
  sqlCommand << "SELECT COUNT(ID) AS unitID FROM UnitType";
  std::string sqlStream = sqlCommand.str();
  
  
  int tableSize = 0;
  int p = sqlite3_open("resources/databases/DungeonCrawler.db", &db);
  if (p) {
    std::cout << (stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return;
  }
  std::cout << "Loading Units.. \n" << std::endl;
  p = sqlite3_exec(db, sqlStream.c_str(), getTableSize, &tableSize, (char**)&errorString[0]);
  if (p != SQLITE_OK) {
    std::cout << (stderr, "SQL error: %s\n", errorString);
    sqlite3_free(db);
    sqlite3_close(db);
    return;
  }
  sqlite3_close(db);

  for (int i = 1; i <= tableSize; ++i) {
    UnitType u;
    u.loadFromDb(i);
    m_unitTypes.push_back(u);
  }
  std::cout << "units loaded... \n" << std::endl;

  /*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
  /**
   * World.cpp loading TileMap
   */
  /*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/



}

/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * World.cpp Lua registration
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

