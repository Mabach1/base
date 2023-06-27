#define STR_DEBUG

#include "base/base.h"

i32 main(i32 argc, char **argv) {
    Arena arena;    

    arena_init(&arena);

    const StringArr args = stringarr_from_args(&arena, argc, argv);

    string_print_format("File name: %", args.arr[0]);

    arena_deinit(&arena);

    return 0;
}
