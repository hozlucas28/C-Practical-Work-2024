
#include "./utilities.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./patterns/main.h"

int countAliveNeighbors(TGame* pGame, int cellRow, int cellCol, int radius) {
    int i;
    int j;

    int startRow = cellRow - radius;
    int startCol = cellCol - radius;

    int endRow = cellRow + radius + 1;
    int endCol = cellCol + radius + 1;

    int aliveNeighbors = 0;

    for (i = startRow; i < endRow; i++) {
        if (i > pGame->rows - 1) break;
        if (i < 0) continue;

        for (j = startCol; j < endCol; j++) {
            if (j > pGame->cols - 1) break;
            if (j < 0) continue;

            if (i == cellRow && j == cellCol) continue;

            if (pGame->dashboard[i][j] == ALIVE_CELL || pGame->dashboard[i][j] == DEAD_CELL_NG)
                aliveNeighbors++;
        }
    }

    return aliveNeighbors;
}

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

    drawPatternInDashboard(pGame, &SPattern);
}

void drawPatternInDashboard(TGame* pGame, TPattern* pPattern) {
    int i;
    int j;

    int pI = 0;
    int pJ = 0;

    int startRow = pGame->center[0] - pPattern->center[0];
    int startCol = pGame->center[1] - pPattern->center[1];

    for (i = startRow; pI < pPattern->rows; i++) {
        if (i < 0) continue;
        if (i > pGame->rows - 1) break;

        for (j = startCol; pJ < pPattern->cols; j++) {
            if (j < 0) continue;
            if (j > pGame->cols - 1) break;

            pGame->dashboard[i][j] = pPattern->arr[pI][pJ];
            pJ++;
        };

        pJ = 0;
        pI++;
    }
}

void fillDashboard(TGame* pGame, char with) {
    int i;
    int j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            pGame->dashboard[i][j] = with;
        }
    }
}

void generateNextGeneration(TGame* pGame) {
    int i;
    int j;

    int aliveNeighbors;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            aliveNeighbors = countAliveNeighbors(pGame, i, j, NEIGHBORHOOD_RADIUS);

            if (pGame->dashboard[i][j] == DEAD_CELL) {
                if (aliveNeighbors == 3) {
                    pGame->cellsDead--;
                    pGame->cellsAlive++;
                    pGame->dashboard[i][j] = ALIVE_CELL_NG;
                };

                continue;
            }

            if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                pGame->cellsAlive--;
                pGame->cellsDead++;
                pGame->dashboard[i][j] = DEAD_CELL_NG;
            };
        }
    }

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            if (pGame->dashboard[i][j] == DEAD_CELL_NG) {
                pGame->dashboard[i][j] = DEAD_CELL;
                continue;
            }

            if (pGame->dashboard[i][j] == ALIVE_CELL_NG) pGame->dashboard[i][j] = ALIVE_CELL;
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

    for (i = 0; i < pGame->cols + 2; i++) printf("-");
    printf("\n");

    for (i = 0; i < pGame->rows; i++) {
        printf("|");
        for (j = 0; j < pGame->cols; j++) {
            printf("%c", pGame->dashboard[i][j]);
        }

        printf("|\n");
    }

    for (i = 0; i < pGame->cols + 2; i++) printf("-");
}

void printGame(TGame* pGame) {
    int i;
    for (i = 0; i < pGame->cols + 2; i++) printf("-");

    printf("\n| Cells alive: %*d |", pGame->cols - 17 + 2, pGame->cellsAlive);
    printf("\n| Cells dead: %*d |", pGame->cols - 16 + 2, pGame->cellsDead);
    printf("\n| Generation: %*d |", pGame->cols - 16 + 2, pGame->generation);
    printf("\n| Maximum generation: %*d |", pGame->cols - 25 + 3, pGame->maximumGeneration);
    printf("\n| Delay between generations: %*d |\n", pGame->cols - 32 + 3,
           pGame->delayBetweenGenerations);

    printDashboardByConsole(pGame);
}
void setDashboardCenter(TGame* pGame) {
    int row = pGame->rows / 2;
    int col = pGame->cols / 2;

    pGame->center[0] = row;
    pGame->center[1] = col;
}

void sleep(int miliseconds) {
    clock_t startTime = clock();
    while (clock() < (startTime + miliseconds))
        ;
}

void startGameByConsole(TGame* pGame, int maxGeneration, int delayBetweenGenerations) {
    int generation = 0;

    pGame->generation = 0;
    pGame->maximumGeneration = maxGeneration;
    pGame->delayBetweenGenerations = delayBetweenGenerations;

    system("cls");
    printGame(pGame);
    if (generation == maxGeneration) return;
    sleep(delayBetweenGenerations);

    while (generation < maxGeneration) {
        generateNextGeneration(pGame);

        generation++;

        pGame->generation = generation;

        system("cls");
        printGame(pGame);
        if (generation != maxGeneration) sleep(delayBetweenGenerations);
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
