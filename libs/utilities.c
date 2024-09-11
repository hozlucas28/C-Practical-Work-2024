#include "utilities.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillDashboard(TGame* pGame, int with) {
    int i;
    int j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            pGame->dashboard[i][j] = with;
        }
    }
}

char* getUserInputStr(char* message, int strLength,
                      int (*validator)(char* userInput)) {
    char* userInput = malloc(strLength * sizeof(char));

    printf("%s", message);
    fflush(stdin);
    fgets(userInput, strLength, stdin);
    trimStr(userInput);

    while (!(*validator)(userInput)) {
        printf("Invalid input! Try again...\n");
        printf("%s", message);
        fflush(stdin);
        fgets(userInput, strLength, stdin);
        trimStr(userInput);
    };

    // TODO

    return userInput;
}

int isStrIn(char* str, char* arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmpi(str, *(arr + i)) == 0) {
            return 1;
        }
    }

    return 0;
}

void printDashboardByConsole(TGame* pGame) {
    int i, j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            printf("%d ", pGame->dashboard[i][j]);
        }
        printf("\n");
    }
}

int strcmpi(const char* str01, const char* str02) {
    int i;

    int lengthStr01 = strlen(str01);
    int lengthStr02 = strlen(str02);
    int shortestLength = lengthStr01 < lengthStr02 ? lengthStr01 : lengthStr02;

    char charStr01;
    char charStr02;
    int cmp = 1;

    for (i = 0; i < shortestLength; i++) {
        charStr01 = toupper(*(str01 + i));
        charStr02 = toupper(*(str02 + i));
        cmp = charStr01 - charStr02;

        if (cmp != 0) {
            return cmp;
        };
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