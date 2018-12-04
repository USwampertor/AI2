/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Resource.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/13 2018
 * @brief Resource
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "Utilities.h"

enum RESOURCETYPE 
{
  SOUND = 0,
  MUSIC,
  TEXTURE,
  FONT
};


 /**
  * Resource
  * Description:
  * 	A resource encapsulation for versatility
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

/**
 * Sound resource based in the Resource class
 */
class Sound : public Resource
{
 public:
  /**
   * Default constructor
   */
  Sound() = default;

  /**/
  Sound(std::string path) {
    m_sound.loadFromFile(path);
  }

  sf::SoundBuffer m_sound;
};

/**
 * Music resource based in the Resource class
 */
class Music : public Resource
{
 public:
  /**
   * Default constructor
   */
  Music() = default;

  /**/
  Music(std::string path) {
    m_music.openFromFile(path);
  }

  sf::Music m_music;
};

/**
 * texture resource based in the Resource class
 */
class Texture : public Resource
{
 public:
  /**
   * Default constructor
   */
  Texture() = default;

  /**/
  Texture(std::string path) {
    m_texture.loadFromFile(path);
  }

  sf::Texture m_texture;
};

/**
 * Font resource based in the Resource class
 */
class Font : public Resource
{
 public:
  /**
   * Default constructor
   */
  Font() = default;

  /**/
  Font(std::string path) {
    m_font.loadFromFile(path);
  }

  /**
   * Font object
   */
  sf::Font m_font;

};