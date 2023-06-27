#include "base/base.h"

#include <stdarg.h>
#include <string.h>

void string_print_format(const char *__format__, ...) {
    u64 num_string = 0;

    for (usize i = 0; i < strlen(__format__); ++i) {
        if ('%' == __format__[i]) {
            ++num_string;
        }
    }

    /* grabing the strings and puting them in string array */
    va_list args;

    va_start(args, __format__);

    Arena scratch;

    arena_init(&scratch);

    StringArr strings = stringarr_alloc(&scratch, num_string);

    for (u64 i = 0; i < num_string; ++i) {
        stringarr_push(&strings, (String)va_arg(args, String));
    }

    va_end(args);


    for (usize i = 0, j = 0; i < strlen(__format__); ++i) {
        if ('%' == __format__[i]) {
            string_print(strings.arr[j++]);
            continue;
        }

        fprintf(stdout, "%c", __format__[i]);
    }

    arena_deinit(&scratch);
}

i32 main(void) {
    Arena arena;

    arena_init(&arena);

    String name = string_from(&arena, "maminka");
    String admin = string_from(&arena, "authentificated user");

    string_print_format("ahoj %, ja se jmenuju %", name, admin);

    arena_deinit(&arena);

    return 0;
}
