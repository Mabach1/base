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
        if (format.ptr[i] != '{') {
            fprintf(stream, "%c", format.ptr[i]);
            continue;
        }

        usize index = string_find_first(format, string_str_lit("{"), i);

        i = index + 2;

        /* we use '%' this for printing parantesises */
        if ('%' == format.ptr[index - 1]) { 
            TODO("printing curly brackets");
            continue;
        }

        if (format.ptr[index+2] != '}') {
            TYPE_ERROR(format.ptr[index+2]);
        }

        switch (format.ptr[index + 1]) {
            case 's': 
                string_print_s(stream, va_arg(args, String));
                break;
            case 'u':
                fprintf(stream, "%llu", va_arg(args, u64));
                break;        
            case 'd':         
                fprintf(stream, "%lld", va_arg(args, i64));
                break;        
            case 'c':         
                fprintf(stream, "%c", va_arg(args, i32));
                break;
            case 'f':
                fprintf(stream, "%lf", va_arg(args, f64));
                break;
            default:
                TYPE_ERROR(format.ptr[index + 1]);
        }
    }

    va_end(args);

    arena_deinit(&scratch);
}
