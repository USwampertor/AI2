/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file Resource.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/13 2018
 * @brief Resource
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
#pragma once

#include "Utilities.h"

 /**
  * Resource
  * Description:
  * 	
  * Sample usage:
  * 	
  */
class Resource
{
public:
  /**
   * Default constructor
   */
  Resource() = default;
  
  /**
   * virtual destructor
   */
  virtual ~Resource() {};
};

class Texture : public Resource
{

};