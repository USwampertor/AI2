/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/
/**
 * @file Utilities.h
 * @author Marco "Swampy" Millan
 * @date 2018/09/28 2018
 * @brief basic things that almost all headers use
 * 
 */
/*||���||���||���||���||���||���||���||���||���||���||���||���||���||���||���||*/

#pragma once

#include <iostream>
#include <thread>
#include <stack>
#include <vector>
#include <sstream>
#include <string>


#include <lua.hpp>
#include <SFML/Graphics.hpp>
#include <sqlite3.h>

static float sqr(float n) { return std::pow(n, 2); }
static float round2(float n) { return std::round(n*2.0f) / 2.0f; }