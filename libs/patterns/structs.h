
#ifndef PATTERNS_STRUCTS_H_INCLUDED
#define PATTERNS_STRUCTS_H_INCLUDED

#include "./macros.h"

// TODO: Documentation
typedef struct {
    char (*arr)[PATTERN_COLS];
    int rows;
    int cols;
} TPattern;

#endif  // PATTERNS_STRUCTS_H_INCLUDED
