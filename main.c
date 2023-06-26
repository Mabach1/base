#include "base/base.h"

i32 main(void) {
    Arena arena;

    arena_init(&arena);

    String str = string_from(&arena, "Hello mom, how are you? :)");

    string_print(str);

    arena_deinit(&arena);

    return 0;
}
