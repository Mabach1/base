#ifndef __MENU_H__
#define __MENU_H__

#include "defines.h"
#include "str.h"

usize menu(StringArr options);
usize menu_ex(StringArr options, usize last_position);
usize menu_ex_cursor(StringArr options, usize last_position);
void menu_pause(void);

#endif
