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
  if (canDecode(RESOURCETYPE::FONT, "resources/fonts/arial.ttf")) {
    loadFromFile(RESOURCETYPE::FONT, "resources/fonts/arial.ttf");
  }
}

void
ResourceManager::garbageCollector() {

}

bool
ResourceManager::canDecode(RESOURCETYPE type, std::string path) {
  if(type == RESOURCETYPE::SOUND) {
    sf::SoundBuffer temp;
    if(!temp.loadFromFile(path)) {
      std::cout << "Couldn't load SFX resource with specified file";
      return false;
    }
  }

  if (type == RESOURCETYPE::MUSIC) {
    sf::Music temp;
    if (!temp.openFromFile(path)) {
      std::cout << "Couldn't load music resource with specified file";
      return false;
    }
  }

  if (type == RESOURCETYPE::TEXTURE) {
    sf::Texture temp;
    if (!temp.loadFromFile(path)) {
      std::cout << "Couldn't load texture resource with specified file";
      return false;
    }
  }

  if (type == RESOURCETYPE::FONT) {
    sf::Font temp;
    if (!temp.loadFromFile(path)) {
      std::cout << "Couldn't load font resource with specified file";
      return false;
    }
  }
  return true;
}

std::shared_ptr<Resource>
ResourceManager::loadFromFile(RESOURCETYPE type, std::string path) {

  //We did find the resource already loaded in the resource map

  if (m_resourceMap.find(path) == m_resourceMap.end()) {
    //Didn't find the resource, therefore we will load it
    
    //We check if its possible to load at given type of resource
    if (!canDecode(type, path)) {
      return nullptr;
    }

    std::shared_ptr<Resource> resource; 

    //Loading the resource
    if (type == RESOURCETYPE::FONT) {
      resource = std::make_shared<Font>(path);
    }
    if (type == RESOURCETYPE::SOUND) {
      resource = std::make_shared<Sound>(path);
    }
    if (type == RESOURCETYPE::MUSIC) {
      resource = std::make_shared<Music>(path);
    }
    if (type == RESOURCETYPE::TEXTURE) {
      resource = std::make_shared<Texture>(path);
    }

    m_resourceMap.insert(std::make_pair(path, resource));
  }
  return m_resourceMap.find(path)->second;
}