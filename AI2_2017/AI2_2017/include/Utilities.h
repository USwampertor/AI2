/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/
/**
 * @file Utilities.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief basic things that almost all headers use
 * 
 */
/*||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||°°°||*/

#pragma once

#include <iostream>
#include <map>
#include <thread>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

#include <lua.hpp>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <rapidjson/allocators.h>
#include <rapidjson/document.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

#include "sqlite3.h"

static float 
sqr(float n) { return std::pow(n, 2); }

static float 
round2(float n) { return std::round(n*2.0f) / 2.0f; }

static int 
getTableSize(void* count, int argc, char** argv, char** azColName) {
  int* c = (int*)count;
  *c = atoi(argv[0]);
  return 0;
}

template<>
struct std::hash<std::string>
{

  int
  operator()(std::string& path) const {
    int hash;
    std::string temp;
    for (unsigned int i = 0; i < path.size(); ++i) {
      int ascii = path[i];
      ascii *= i + 1;
      temp.append(std::to_string(ascii));
    }
    hash = atoi(temp.c_str());
    return hash;
  }
};
