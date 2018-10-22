/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file World.h
 * @author Marco "Swampy" Millan
 * @date 2018/10/20 2018
 * @brief 
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once


#include "ItemType.h"
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

 public:
  
   std::vector<Unit> m_unitsInGame;

   std::vector<UnitType> m_unitTypes;

   std::vector<ItemType> m_itemTypes;
};

