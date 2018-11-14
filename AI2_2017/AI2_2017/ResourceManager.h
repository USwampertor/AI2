/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file ResourceManager.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/12 2018
 * @brief Resource manager in charge of loading and unload
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "Utilities.h"
#include "Resource.h"

 /**
  * Resource Manager
  * Description:
  * 	In charge of all the files and objects in the game
  * Sample usage:
  * 	
  */
class ResourceManager
{
public:
  ResourceManager() = default;
  ~ResourceManager() {};

  /**
   * @brief initializes and loads the sprites
   * @param 
   * @return 
   *
   */
  void
  initialize();

  /**
   * @brief Loads a file and hashes the string of the path
   * @param
   * @return
   *
   */
  void
  loadFromFile();

  /**
   * @brief Checks if there is any resource to destroy
   * @param
   * @return
   *
   */
  void
  garbageCollector();


  /**
   * Member declaration
   */
 public:
  
  /**
   * hashed map
   */
   std::map<std::string, std::shared_ptr<Resource>> m_resourceMap;
};

