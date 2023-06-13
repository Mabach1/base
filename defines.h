#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <stdio.h>

#define table_len(table) sizeof (table) / sizeof (*table)

/* types */
typedef unsigned char                  u8;
typedef unsigned short                u16;
typedef unsigned int                  u32;
typedef unsigned long long            u64;
                                    
typedef signed char                    s8;
typedef signed short                  s16;
typedef signed int                    s32;
typedef signed long long              s64;
                                    
typedef char                           i8;
typedef short                         i16;
typedef int                           i32;
typedef long long                     i64;
                                    
typedef float                         f32;
typedef double                        f64;
typedef long double                  f128;
                                    
typedef size_t                      usize;
typedef ssize_t                     isize;

#define USIZE_MAX    0xffffffffffffffffULL 

/* boolean */
typedef enum { false, true } bool;

/* memory size */
#define Bytes(x)     ((u64) x)
#define KiloBytes(x) ((u64) x * 1024) 
#define MegaBytes(x) ((u64) x * 1024 * 1024) 
#define GigaBytes(x) ((u64) x * 1024 * 1024 * 1024)


#endif
