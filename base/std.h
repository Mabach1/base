#ifndef __STD_H__
#define __STD_H__

#include <stdio.h>

#include "str.h"

void std_print_stream(FILE *stream, const char * __format, ...);
String std_read_until_delimiter_or_eof(Arena *allocator, String delimiter);

#endif
