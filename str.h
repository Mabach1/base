#ifndef __STR_H__
#define __STR_H__

#include "defines.h"
#include "mem.h"

#define STRING_DEFAULT_SIZE (32)

typedef struct String {
    u8 *data;
    usize len;  
} String;

typedef struct StringArr {
    String *arr;
    usize len;
    usize cap;
} StringArr;

/* string */
String string_from(Arena *arena, const u8 *content);
String string_from_stdin(Arena *arena);
StringArr string_from_args(Arena *arena, u32 argc, char **argv);
String string_str_lit(const u8 *lit);

void string_print(const String str);
const char *string_get_lit(const String str);

i8 string_compare(const String str1, const String str2);
bool string_equal(const String str1, const String str2);
bool string_is_null(const String str);

usize string_find_first(const String haystack, const String needle, u32 offset);
usize string_find_last(const String haystack, const String needle, u32 offset);
u64 string_substr_count(const String haystack, const String needle);

String string_replace_all(Arena *arena, const String to_fix, const String needle, const String replacement);
String string_cat(Arena *arena, const String str1, const String str2);
String string_copy(Arena *arena, const String source, usize destination_size);
String string_dup(Arena *arena, const String source);
StringArr string_parse(Arena *arena, String *str, const u8 *delimiters);

/* string array */
StringArr stringarr_alloc(Arena *arena, usize size);
bool stringarr_push(StringArr *str_arr, const String str);
bool stringarr_remove(StringArr *str_arr, usize index);
bool stringarr_insert(StringArr *str_arr, usize index, String src);
void stringarr_push_multiple(StringArr *arr, u64 number_of_strings, ...);

void stringarr_print(const StringArr list);

#ifdef STRING_DEBUG

void string_log(const String str);
void stringarr_log(StringArr list);

#endif

/* use this only in dire situations, it doesnt rely on arena allocator */
#ifdef USING_STRINGVEC

#define STRINGVEC_DEFAULT_SIZE  (16)

typedef struct StringVec {
    String *str;
    usize len;
    usize cap;
} StringVec;

StringVec stringvec_new(void);
void stringvec_delete(StringVec *str_vec);

void stringvec_print(const StringVec str_vec);
void stringvec_push(StringVec *str_vec, const String str);

#endif

#endif /* __STR_H__ */
