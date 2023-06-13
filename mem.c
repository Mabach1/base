#include "mem.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdarg.h>

void arena_init(Arena *arena) {
    /* can be swaped for different memory allocator */
    arena->memory = malloc(ARENA_MAX_SIZE);

    arena->max = ARENA_MAX_SIZE;
    arena->alloc_position = 0;
    arena->commit_position = 0;
}

void arena_deinit(Arena *arena) {
    /* if we use different allocator in the init function, we have to use appropriate deallocator */
    free(arena->memory);

    arena->alloc_position = 0;
    arena->commit_position = 0;
    arena->max = 0;
}

/* instead of u64, there should be uintptr_t, but im doing this machine specific (my machine) */
bool is_power_of_two(u64 value) {
    return (value & (value - 1)) == 0;
}

u64 align_forward(u64 ptr, usize align) {
    assert(is_power_of_two(align));

    u64 p = ptr;
    u64 a = (u64)align;

    u64 modulo = p & (a - 1);

    if (modulo != 0) {
        p += a - modulo;
    }

    return p;
}

void *arena_alloc(Arena *arena, usize size) {
    u64 current_ptr = (u64)arena->memory + (u64)arena->alloc_position;
    u64 offset = align_forward(current_ptr, DEFAULT_ALIGMENT) - (u64)arena->memory;

    if (offset + size > arena->max) {
        fprintf(stderr, "Error: Out of bounds (Exceeded the memory allocated for the given area)!\nAborting...\n");
        exit(1);
    }

    /* the actual used memory */
    void *memory = &arena->memory[offset];

    arena->commit_position = offset;
    arena->alloc_position = offset + size;

    return memory;
}

void *arena_alloc_zero(Arena *arena, usize size) {
    void *memory = arena_alloc(arena, size);

    memset(memory, 0, size);

    return memory;
}

void *arena_resize(Arena *arena, void *ptr, usize size) {
    void *raised = arena_alloc(arena, size);

    memcpy(raised, ptr, size);

    return raised;
}
