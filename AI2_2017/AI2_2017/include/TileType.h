/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file TileType.h
 * @author Marco "Swampy" Millan
 * @date 2018/12/04 2018
 * @brief Tiletype is a "template" for different tiles
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
#pragma once

#include "Utilities.h"
#include "Frame.h"

class TileType
{
public:
  /**
   * Default constructor
   */
  TileType() = default;

  /**
   * Copy constructor
   */
  TileType(const TileType& other) 
    : m_name(other.m_name),
      m_resource(other.m_resource),
      m_typeID(other.m_typeID),
      m_rectangle(other.m_rectangle) {}

  /**
   * Default destructor
   */
  ~TileType() {}

  /**
   * @brief loads the info from a database
   * @param id of the unit type
   * @return 
   *
   */
  void
  loadFromDb(const int id);

public:

  std::string m_name;

  std::string m_resource;

  int m_typeID;

  Frame m_rectangle;
};

