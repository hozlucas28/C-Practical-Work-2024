
#include "./utilities.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./patterns/main.h"

void destroy2DArray(char** arr, int rows, int cols) {
    int i;

    for (i = 0; i < rows; i++) {
        free(*(arr + i));
    }

    free(arr);
}

int drawDashboardFromFile(char* filePath, TGame* pGame) {
    FILE* pf;

    char* line;
    int lineLength = 100;

    char* row;
    char* col;
    char* sep;

    int rowInt;
    int colInt;

    int rows = pGame->rows;
    int cols = pGame->cols;

    pf = fopen(filePath, "rt");
    if (pf == NULL) return 0;

    line = malloc(sizeof(char) * (lineLength + 1));
    if (line == NULL) {
        fclose(pf);
        return 0;
    };
    *(line + lineLength) = '\0';

    fgets(line, lineLength, pf);

    while (fgets(line, lineLength, pf)) {
        row = line;
        sep = strrchr(line, ';');
        if (sep == NULL) continue;

        *sep = '\0';
        col = sep + 1;

        sscanf(row, "%d", &rowInt);
        sscanf(col, "%d", &colInt);

        if (rowInt > rows) rows = rowInt;
        if (colInt > cols) cols = colInt;
    }

    printf("\n\n> rows: %d\n", rows);
    printf("> cols: %d\n\n", cols);

    // TODO: draw in dashboard.

    return 1;
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

char** new2DArray(int rows, int cols) {
    char** bidimensionalArr;

    int i;
    int j;

    bidimensionalArr = malloc(rows * sizeof(char*));
    if (bidimensionalArr == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < rows; i++) {
        *(bidimensionalArr + i) = malloc(cols * sizeof(char));
        if (*(bidimensionalArr + i) == NULL) {
            for (j = 0; j < i; j++) free(*(bidimensionalArr + j));
            printf("Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    return bidimensionalArr;
}

void sleep(int miliseconds) {
    clock_t startTime = clock();
    while (clock() < (startTime + miliseconds));
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
    }

    *(str + strLength - counter) = '\0';
}
