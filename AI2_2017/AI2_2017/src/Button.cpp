/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/
/**
 * @file Button.cpp
 * @author Marco "Swampy" Millan
 * @date 2018/10/15 2018
 * @brief Button member definition
 * 
 */
/*||偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|偽院|*/

#include "Button.h"

void
Button::onClick() {
  std::string p = m_text.getString();
  std::cout << "clicked" << p << std::endl;
  m_clicked = true;
}
