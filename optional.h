/*
 * This code is distributed under the terms of the GNU General Public License.
 * For more information, please refer to the LICENSE file in the root directory.
 * -------------------------------------------------
 * Copyright (C) 2025 Rodrigo R.
 * This program comes with ABSOLUTELY NO WARRANTY; for details type show w'.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions; type show c' for details.
*/

#ifndef FLUENT_LIBC_OPTIONAL_LIBRARY_H
#define FLUENT_LIBC_OPTIONAL_LIBRARY_H

// ============= FLUENT LIB C =============
// optional_t API
// ----------------------------------------
// A simple optional value wrapper for C.
// Allows you to safely represent a value that may or may not exist.
// Inspired by std::optional in C++ and Option in Rust.
//
// Helps avoid NULL pointer bugs and makes intent clearer.
//
// Features:
// - optional_empty:    Create an empty optional (no value).
// - optional_some:     Wrap a value inside an optional.
// - optional_is_empty: Check if the optional contains a value.
// - optional_unwrap:   Safely access the value inside the optional.
//                      Panics (exits) if no value is present.
//
// Function Signatures:
// ----------------------------------------
// optional_t optional_empty(void);
//     Example:
//         optional_t opt = optional_empty();
//
// optional_t optional_some(void *value);
//     Example:
//         int x = 10;
//         optional_t opt = optional_some(&x);
//
// int optional_is_empty(const optional_t opt);
//     Example:
//         if (!optional_is_empty(opt)) { /* safe to unwrap */ }
//
// void *optional_unwrap(const optional_t opt);
//     Example:
//         int *val = (int *)optional_unwrap(opt);
//
// ----------------------------------------
// Initial revision: 2025-05-26
// ----------------------------------------
// Depends on: stdio.h, stdlib.h
// ----------------------------------------

// ============= INCLUDES =============
#include <stdio.h> // puts
#include <stdlib.h> // exit, size_t

// ============= FLUENT LIB C++ =============
#if defined(__cplusplus)
extern "C"
{
#endif

#define DEFINE_OPTIONAL_T(K, NAME)                              \
    typedef struct                                              \
    {                                                           \
        K value;                                                \
        int has_value;                                          \
    } optional_##NAME##_t;                                      \
                                                                \
    static inline optional_##NAME##_t optional_##NAME##_empty(void) \
    {                                                           \
        optional_##NAME##_t opt;                                \
        opt.value = (K){0};                                     \
        opt.has_value = 0;                                      \
        return opt;                                             \
    }                                                           \
                                                                \
    static inline optional_##NAME##_t optional_##NAME##_some(K value) \
    {                                                           \
        optional_##NAME##_t opt;                                \
        opt.value = value;                                      \
        opt.has_value = 1;                                      \
        return opt;                                             \
    }                                                           \
                                                                \
    static inline int optional_##NAME##_is_empty(const optional_##NAME##_t opt) \
    {                                                           \
        return !opt.has_value;                                  \
    }                                                           \
                                                                \
    static inline K optional_##NAME##_unwrap(const optional_##NAME##_t opt) \
    {                                                           \
        if (opt.has_value)                                      \
        {                                                       \
            return opt.value;                                   \
        }                                                       \
                                                                \
        puts("Error: Attempted to unwrap an optional with no value."); \
        exit(1);                                                \
    }

#ifndef FLUENT_LIBC_GENERIC_OPTIONAL_DEFINED
#   define FLUENT_LIBC_GENERIC_OPTIONAL_DEFINED 1
    DEFINE_OPTIONAL_T(void *, generic)
#endif // FLUENT_LIBC_GENERIC_OPTIONAL_DEFINED

// ============= FLUENT LIB C++ =============
#if defined(__cplusplus)
}
#endif

#endif //FLUENT_LIBC_OPTIONAL_LIBRARY_H