/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file ResourceManager.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/11/12 2018
 * @brief resource manager member definition
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#include "ResourceManager.h"

void
ResourceManager::initialize() {

}

void
ResourceManager::garbageCollector() {

}

std::shared_ptr<Resource>
ResourceManager::loadFromFile(std::string path) {

  //We did find the resource already loaded in the resource map
  if (m_resourceMap.find(path) == m_resourceMap.end()) {
    //returns the resource
  }
  return m_resourceMap.find(path)->second;
}