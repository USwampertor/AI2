/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file Animation.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief Animation struct for saving all the frames of the object
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#pragma once
#include "Frame.h"
#define MAXFRAMES 10
/**
 * The action of the unit
 */
enum ANIM {
  IDLE = 0,
  RUN,
  ATTACK,
  DEAD,
  NUM_ANIMS = 4
};

/**
 * The direction of the unit
 */
enum DIR {
  NORTH = 0,
  NWEST = 1,
  WEST = 2,
  SWEST = 3,
  SOUTH = 4,
  SEAST = SWEST,
  EAST = WEST,
  NEAST = NWEST,
  NUM_DIRS = 5
};

/**
 * The animation set of the object
 */
struct Animation
{
  std::vector< std::vector< std::vector< Frame > > > m_frame;
  //Frame m_frame[NUM_ANIMS][NUM_DIRS][MAXFRAMES];
};