
#ifndef PATTERNS_STRUCTS_H_INCLUDED
#define PATTERNS_STRUCTS_H_INCLUDED

#include "./macros.h"

/**
 * @struct TPattern
 * @brief Represents a pattern structure.
 *
 * This structure is used to represent a pattern in a 2D array. It contains a 2D array representing
 * the pattern, as well as other properties such as the number of rows and columns of the pattern.
 */
typedef struct {
    char** arr;    /** 2D array representing the pattern. */
    int rows;      /** Number of rows of the pattern. */
    int cols;      /** Number of columns of the pattern. */
    int center[2]; /** Array (row, and column) representing the center of the pattern. */
} TPattern;

#endif  // PATTERNS_STRUCTS_H_INCLUDED
