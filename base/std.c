#include "std.h"
#include "mem.h"
#include "str.h"

#include <stdarg.h>

#define TYPE_ERROR(c) ASSERT(0, "\nError: Incorrect type specifier in print function: '%c', Exiting with '1'\n", c)

void std_print_stream(FILE *stream, const char * __format, ...) {
    Arena scratch;

    arena_init(&scratch);

    String format = string_from(&scratch, __format);

    va_list args;

    va_start(args, __format); 

    for (usize i = 0; i < format.len; ++i) {
        if (format.data[i] != '{') {
            fprintf(stream, "%c", format.data[i]);
            continue;
        }

        usize index = string_find_first(format, string_str_lit("{"), i);

        i = index + 2;

        /* we use '`' this for printing parantesises */
        if ('%' == format.data[index - 1]) { 
            continue;
        }

        if (format.data[index+2] != '}') {
            TYPE_ERROR(format.data[index+2]);
        }

        switch (format.data[index + 1]) {
            case 's': 
                string_print_s(stream, va_arg(args, String));
                break;
            case 'u':
                fprintf(stream, "%u", va_arg(args, u64));
                break;        
            case 'd':         
                fprintf(stream, "%d", va_arg(args, i64));
                break;        
            case 'c':         
                fprintf(stream, "%c", va_arg(args, i32));
                break;
            default:
                TYPE_ERROR(format.data[index + 1]);
        }
    }

    va_end(args);

    arena_deinit(&scratch);
}

