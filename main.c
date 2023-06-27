#include "base/base.h"


i32 main(void) {
    Arena arena;

    arena_init(&arena);

    String str = stirng_from_format(&arena, "Hello mom, random number of the day is: %d", 5);

    string_print(str);

    arena_deinit(&arena);

    return 0;
}
