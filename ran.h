#ifndef __RAN_H__
#define __RAN_H__

#include "defines.h"

#ifdef __MINGW32__  /* these functions work using winddows libraries */

u64 ran_rand(void);

#endif

#endif
