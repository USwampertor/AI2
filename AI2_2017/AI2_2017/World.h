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

#include "Utilities.h"
#include "Unit.h"
#include "UnitType.h"
class World
{
public:
  World() = default;
  ~World();

 public:
  
   std::vector<Unit> m_unitsInGame;

   std::vector<UnitType> m_unitTypes;


};

