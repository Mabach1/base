#include "base/base.h"

i32 main(void) {
    Arena arena;    

    arena_init(&arena);

    String person = string_from(&arena, "mami");

    std_print_stream(stdout, "ahoj {s}", person);

    arena_deinit(&arena);

    return 0;
}
