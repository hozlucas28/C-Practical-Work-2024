#include "utilities.h"

#include <stdio.h>

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

void printDashboard(TGame* pGame) {
    int i, j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            printf("%d ", pGame->dashboard[i][j]);
        }
        printf("\n");
    }
}
