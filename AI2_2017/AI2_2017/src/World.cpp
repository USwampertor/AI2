#include "World.h"


void
World::initialization() {
  sqlite3* db;
  std::string errorString;

  errorString.resize(128);
  
  
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * World.cpp loading of unitTypes
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
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

  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
  /**
   * World.cpp loading TileMap
   */
  /*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/



}

void
World::createUnit(int id, Vector2 position) {
  
  Unit* u = new Unit(*getUnitType(id));
  u->setID(id_Creator);
  u->setPosition(position);
  u->m_SpriteResource = 
    std::static_pointer_cast<Texture>(m_resourceManager->loadFromFile(RESOURCETYPE::TEXTURE,
                                                         getUnitType(id)->m_source));
  u->initialize();
  m_unitsInGame.push_back(u);
  ++id_Creator;
}

UnitType*
World::getUnitType(int id) {
  return &m_unitTypes[id];
}

void
World::clearActiveUnits() {
  m_activeUnits.clear();
}

void
World::insertActiveUnits(Frame collider) {
  for (int i = 0; i < m_unitsInGame.size(); ++i) {
    Frame t = { m_unitsInGame[i]->m_actualFrame.size,m_unitsInGame[i]->getPosition(),false };
    if (isColliding(collider, t)) { 
      m_activeUnits.push_back(m_unitsInGame[i]); 
    }
  }
}

/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * World.cpp Lua registration
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

