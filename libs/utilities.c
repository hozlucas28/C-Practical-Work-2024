
#include "./utilities.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./patterns/main.h"

void drawPattern(TGame* pGame, char* pattern) {
    TPattern SPattern;

    char arr[PATTERN_ROWS][PATTERN_COLS];

    SPattern.arr = arr;

    fillDashboard(pGame, DEAD_CELL);

    if (strcmpi(pattern, "glider") == 0) {
        newGliderPattern(&SPattern);
        pGame->cellsAlive = 5;
    } else if (strcmpi(pattern, "glider cannon") == 0) {
        newGliderCannonPattern(&SPattern);
        pGame->cellsAlive = 36;
    } else if (strcmpi(pattern, "press") == 0) {
        newPressPattern(&SPattern);
        pGame->cellsAlive = 48;
    } else if (strcmpi(pattern, "toad") == 0) {
        newToadPattern(&SPattern);
        pGame->cellsAlive = 6;
    } else {
        return;
    }

    pGame->cellsDead = (pGame->cols * pGame->rows) - pGame->cellsAlive;
    pGame->generation = 0;

    printf("\n\n");                    // TODO: Remove line.
    printPatternByConsole(&SPattern);  // TODO: Remove line.

    // TODO
    drawPatternInDashboard(pGame, &SPattern);

    printf("\n* The '%s' pattern was injected! *", pattern);  // TODO: Remove line.
    printf("\n* The '%s' pattern was drawn! *", pattern);     // TODO: Remove line.
}

// TODO
void drawPatternInDashboard(TGame* pGame, TPattern* pattern) {}

void fillDashboard(TGame* pGame, char with) {
    int i;
    int j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            pGame->dashboard[i][j] = with;
        }
    }
}

char* getUserInputStr(char* message, char* onInvalidMessage, int strLength,
                      int (*validator)(char* userInput)) {
    char* userInput = malloc(strLength * sizeof(char));
    if (userInput == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    printf(message);
    fflush(stdin);
    fgets(userInput, strLength, stdin);
    trimStr(userInput);

    while (!(*validator)(userInput)) {
        puts(onInvalidMessage);
        printf(message);
        fflush(stdin);
        fgets(userInput, strLength, stdin);
        trimStr(userInput);
    };

    return userInput;
}

int isStrIn(char* str, char* arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmpi(str, *(arr + i)) == 0) return 1;
    }

    return 0;
}

void printDashboardByConsole(TGame* pGame) {
    int i;
    int j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            printf("%c", pGame->dashboard[i][j]);
        }

        printf("\n");
    }
}

int strcmpi(const char* str01, const char* str02) {
    int i;

    int lengthStr01 = strlen(str01);
    int lengthStr02 = strlen(str02);

    char charStr01;
    char charStr02;
    int cmp = 1;

    if (lengthStr01 != lengthStr02) return lengthStr01 > lengthStr02 ? 1 : -1;

    for (i = 0; i < lengthStr01; i++) {
        charStr01 = toupper(*(str01 + i));
        charStr02 = toupper(*(str02 + i));
        cmp = charStr01 - charStr02;

        if (cmp != 0) return cmp;
    };

    return cmp;
}

void trimStr(char* str) {
    trimLeftStr(str);
    trimRightStr(str);
}

void trimLeftStr(char* str) {
    int i;
    int j;
    int strLength = strlen(str);

    int counter = 0;

    for (i = 0; i < strLength; i++) {
        if (!isspace(*(str + i))) break;
        counter++;
    };

    for (j = 0; j < strLength - counter; j++) {
        *(str + j) = *(str + j + counter);
    };

    *(str + strLength - counter) = '\0';
}

void trimRightStr(char* str) {
    int i;
    int strLength = strlen(str);

    int counter = 0;

    for (i = strLength - 1; i > 0; i--) {
        if (!isspace(*(str + i))) break;
        counter++;
    }

    *(str + strLength - counter) = '\0';
}
