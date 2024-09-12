
#include <stdio.h>

#include "./structs.h"

void fillPattern(TPattern* pPattern, char with) {
    int i;
    int j;

    for (i = 0; i < pPattern->rows; i++) {
        for (j = 0; j < pPattern->cols; j++) {
            pPattern->arr[i][j] = with;
        }
    }
}

void printPatternByConsole(TPattern* pPattern) {
    int i;
    int j;

    for (i = 0; i < pPattern->rows; i++) {
        for (j = 0; j < pPattern->cols; j++) {
            printf("%c", pPattern->arr[i][j]);
        }

        printf("\n");
    }
}