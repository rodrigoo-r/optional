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

/**
 * @brief Represents an optional value.
 *
 * The optional_t struct can either contain a pointer to a value (when present)
 * or indicate the absence of a value.
 */
typedef struct
{
    void *value;        ///< Pointer to the value, NULL if not present
    int has_value;      ///< Flag indicating if a value is present (1) or not (0)
} optional_t;

/**
 * @brief Creates an empty optional (no value present).
 *
 * @return An optional_t with no value.
 */
static inline optional_t optional_empty(void)
{
    optional_t opt;

    // Initialize the optional to be empty
    opt.value = NULL;
    opt.has_value = 0;
    return opt;
}

/**
 * @brief Creates an optional containing a value.
 *
 * @param value Pointer to the value to store.
 * @return An optional_t containing the given value.
 */
static inline optional_t optional_some(void *value)
{
    optional_t opt;

    // Initialize the optional with the provided value
    opt.value = value;
    opt.has_value = 1; // Indicate that a value is present
    return opt;
}

/**
 * @brief Checks if the optional is empty (no value present).
 *
 * @param opt The optional to check.
 * @return 1 if empty, 0 otherwise.
 */
static inline int optional_is_empty(const optional_t opt)
{
    return !opt.has_value;
}

/**
 * @brief Retrieves the value from the optional.
 *
 * @param opt The optional to unwrap.
 * @return Pointer to the value if present.
 * @note If the optional is empty, prints an error and exits the program.
 */
static inline void *optional_unwrap(const optional_t opt)
{
    // Warning: Should always use optional_is_empty() before this function
    if (opt.has_value)
    {
        return opt.value;
    }

    // If no value is present, panic
    puts("Error: Attempted to unwrap an optional with no value.");
    exit(1);
}

// ============= FLUENT LIB C++ =============
#if defined(__cplusplus)
}
#endif

#endif //FLUENT_LIBC_OPTIONAL_LIBRARY_H