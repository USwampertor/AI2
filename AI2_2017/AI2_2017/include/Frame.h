/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Vertex.h
 * @author Marco "Swampy" Millan
 * @date 2018/11/06 2018
 * @brief Sprite struct to save the info of the unit or gameObject
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once
#include "Vector2.h"

struct Frames
{

};


struct Frame
{

  Frame() {}

  Frame(Vector2 s, Vector2 pos = { 0,0 }, bool flip = false)
    : position(pos),
      size(s),
      m_flipped(flip) {}
  /**
   * Position in sprite sheet
   */
  Vector2 position;

  /**
   * Size of rect in sprite sheet
   */
  Vector2 size;

  /**
   * Checks if the frame should be flipped on X
   */
  bool m_flipped = true;
};