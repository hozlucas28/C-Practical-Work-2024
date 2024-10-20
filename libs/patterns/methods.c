
#include "./methods.h"

#include <stdio.h>

#include "./structs.h"

void fillPattern(TPattern* pPattern, const char with) {
    size_t i;
    size_t j;

    for (i = 0; i < pPattern->rows; i++) {
        for (j = 0; j < pPattern->cols; j++) {
            pPattern->arr[i][j] = with;
        }
    }
}

void printPatternByConsole(TPattern* pPattern) {
    size_t i;
    size_t j;

    for (i = 0; i < pPattern->rows; i++) {
        for (j = 0; j < pPattern->cols; j++) {
            printf("%c", pPattern->arr[i][j]);
        }

        printf("\n");
    }
}

void setPatternCenter(TPattern* pPattern) {
    const int row = pPattern->rows / 2;
    const int col = pPattern->cols / 2;

    pPattern->center[0] = row;
    pPattern->center[1] = col;
}