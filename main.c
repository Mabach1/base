#include "base/base.h"

i32 main(void) {
    Arena arena;

    arena_init(&arena);

    String str = string_from(&arena, "Hello mom, how are you? :)");

    string_print(str);

    fprintf(stdout, "Here is the random number of the day: %llu", ran_rand());

    arena_deinit(&arena);

    return 0;
}
