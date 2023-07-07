#include "base/base.h"

i32 main(i32 argc, char **argv) {
    Arena arena;    

    arena_init(&arena);

    FILE *file = fopen("text.txt", "w");

    ASSERT(file, "Error: coudnt open!\n");

    String message = string_from(&arena, "Ahoj mami");

    std_print_stream(file, "message: {s}", message);

    fclose(file);

    arena_deinit(&arena);

    return 0;
}
