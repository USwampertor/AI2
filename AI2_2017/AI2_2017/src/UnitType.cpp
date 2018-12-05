/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file UnitType.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/12/04 2018
 * @brief member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#include "UnitType.h"
//#include "sqlite3.h"

int
mountUnit(void* data, int count, char** value, char** columns) {


  //LOad default data from the database to unitType
  UnitType* p = (UnitType*)data;

  p->m_typeID = atoi(value[0]);
  p->m_name = value[1];
  p->m_hp = atoi(value[2]);
  p->m_speed = atoi(value[3]);
  p->m_strength = atoi(value[4]);  
  p->m_defense = atoi(value[5]);
  p->m_source = "resources/sprites/defaultSprite.png";
  
  p->m_anim.m_frame.resize(ANIM::NUM_ANIMS);

  //for (int i = 0; i < p->m_anim.m_frame.size(); ++i) {
  //  p->m_anim.m_frame[i].resize(DIR::NUM_DIRS);
  //}

  //Gets all the frames per each action that it does
  std::string framesPerAction = value[9];
  std::istringstream buffer(framesPerAction);
  SIZE_T temp;

  //Iterates throught the first vector -------
  for (unsigned int i = 0; i < p->m_anim.m_frame.size(); ++i) {
    //Resizes each of the objects in the vector - - - - -
    //so it is now a matrix                     | | | | |
    p->m_anim.m_frame[i].resize(DIR::NUM_DIRS);

    //Iterates throught the second level of vectors
    for (unsigned int j = 0; j < p->m_anim.m_frame[i].size(); ++j) {

      //Resizes each vector of vector so each of them has the specific amount of frames
      // / / / / /
      // - - - - -
      // | | | | |
      buffer >> temp;
      p->m_anim.m_frame[i][j].resize(temp);

    }
  }
  //Check if UnitType has defined any sprites inside
  if (atoi(value[6]) != 0) {
    //Load sprite info
    std::string temp = value[7];
    p->loadSprites(temp);
    p->m_source = value[8];

  }

  return 0;
}

void
UnitType::loadSprites(std::string spriteName) {
  std::istringstream buffer(spriteName);
  
  //int position = 0;
  //Here we would use the json file to reach the objects inside of it and set the textures
  for (unsigned int i = 0; i < ANIM::NUM_ANIMS; ++i) {
    
    std::cout << "ANIMATION BATCH " << i << std::endl;
    for (unsigned int j = 0; j < DIR::NUM_DIRS; ++j) {
      std::cout << "DIRECTION BATCH" << j << std::endl;
      for (unsigned int k = 0 ; k < this->m_anim.m_frame[i][j].size(); ++k) {
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

  p = sqlite3_exec(db, sqlStream.c_str(), mountUnit, this, (char**)&errorCatcher[0]);
  if (p != SQLITE_OK) {
    std::cout << (stderr, "SQL error: %s\n", errorCatcher);
    sqlite3_free(db);
  }

  sqlite3_close(db);
}
