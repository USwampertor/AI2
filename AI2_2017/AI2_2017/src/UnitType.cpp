#include "UnitType.h"
//#include "sqlite3.h"

int
mountData(void* data, int count, char** value, char** columns) {


  //LOad default data from the database to unitType
  UnitType* p = (UnitType*)data;

  p->m_typeID = atoi(value[0]);
  p->m_name = value[1];
  p->m_hp = atoi(value[2]);
  p->m_speed = atoi(value[3]);
  p->m_strength = atoi(value[4]);  
  p->m_defense = atoi(value[5]);

  //Check if UnitType has defined any sprites inside
  if (atoi(value[6]) != 0) {
    //Load sprite info
    std::string temp = value[7];
    p->loadSprites(temp);
    p->m_source = value[8];
    //return 0;
  }

  return 0;
}

void
UnitType::loadSprites(std::string spriteName) {
  std::istringstream buffer(spriteName);
  
  ANIM anim;
  DIR dir;
  
  Rect temp;

  int position = 0;
  //Here we would use the json file to reach the objects inside of it and set the textures
  for (int i = 0; i < ANIM::NUM_ANIMS; ++i) {
    
    std::cout << "ANIMATION BATCH " << i << std::endl;
    for (int j = 0; j < DIR::NUM_DIRS; ++j) {
      std::cout << "DIRECTION BATCH" << j << std::endl;
      for (int k = 0 ; k < 10; ++k) {
        std::string t;
   
        buffer >> this->m_anim.m_frame[i][j][k].position.x;
        buffer >> this->m_anim.m_frame[i][j][k].position.y;
        buffer >> this->m_anim.m_frame[i][j][k].size.x;
        buffer >> this->m_anim.m_frame[i][j][k].size.y;
        std::cout << this->m_anim.m_frame[i][j][k].position.x << std::endl;
      }
    }

  }
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
