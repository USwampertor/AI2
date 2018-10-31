/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file World.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief 
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once


#include "ItemType.h"
#include "Tile.h"
#include "Unit.h"
#include "UnitType.h"
#include "Utilities.h"


class World
{
public:
  World() = default;
  ~World() {
    m_unitsInGame.clear();
    m_unitTypes.clear();
    m_itemTypes.clear();
  };

  /**
   * initialization of world
   */
  void
  initialization();
  
  void
  createUnit(int id);

  void
  createUnitType(int id);

  UnitType* 
  getUnitType(int id);

 public:
  
  /**
   * the list of all units in-game
   */
  std::vector<Unit> m_unitsInGame;
  
  /**
   * List of all unitTypes from data base
   */
  std::vector<UnitType> m_unitTypes;
  
  /**
   * list of item types from database
   */
  std::vector<ItemType> m_itemTypes;

  /**
   * tileMap Atlas
   */
  std::vector<Tile> m_tileMap;

};

