#ifndef __MEM_H__
#define __MEM_H__ 

#include "defines.h"

#define DEFAULT_ALIGMENT    sizeof(void *)
#define ARENA_MAX_SIZE      MegaBytes(32)   

typedef struct Arena {
    u8 *memory;
    usize max;
    usize alloc_position;
    usize commit_position;
} Arena;

void arena_init(Arena *arena);
void arena_deinit(Arena *arena);

void *arena_alloc(Arena *arena, usize size);
void *arena_alloc_zero(Arena *arena, usize size);
void *arena_resize(Arena *arena, void *ptr, usize size);

#endif /* __MEM_H__ */
