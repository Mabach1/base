#ifndef __MENU_H__
#define __MENU_H__

#include "defines.h"
#include "str.h"

usize menu(String name, StringArr options);
usize menu_ex(String name, StringArr options, usize last_position);
usize menu_ex_cursor(String name, StringArr options, usize last_position);
void menu_pause(String msg);

#endif
