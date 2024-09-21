
#include "./methods.h"

#include <limits.h>
#include <stdio.h>

#include "../patterns/main.h"
#include "./macros.h"
#include "./structs.h"

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
    destroyMatrix(SPattern.arr, SPattern.rows, SPattern.cols);
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

void printDashboardByConsole(TGame* pGame) {
    int i;
    int j;

    for (i = 0; i < pGame->rows; i++) {
        printf("\n");

        for (j = 0; j < pGame->cols; j++) {
            printf("%c", pGame->dashboard[i][j]);
        }
    }
}

void printGameByConsole(TGame* pGame) {
    int i;
    int j;

    // Print header
    for (i = 0; i < pGame->cols + 2; i++) printf("-");

    printf("\n| Cells alive: %*d |", pGame->cols - 17 + 2, pGame->cellsAlive);
    printf("\n| Cells dead: %*d |", pGame->cols - 16 + 2, pGame->cellsDead);
    printf("\n| Generation: %*d |", pGame->cols - 16 + 2, pGame->generation);

    if (pGame->maximumGeneration == INT_MAX) {
        printf("\n| Maximum generation: %*s |", pGame->cols - 25 + 3, "infinity");
    } else {
        printf("\n| Maximum generation: %*d |", pGame->cols - 25 + 3, pGame->maximumGeneration);
    }

    printf("\n| Delay between generations: %*d ms |\n", pGame->cols - 35 + 3,
           pGame->delayBetweenGenerations);

    // Print dashboard
    for (i = 0; i < pGame->cols + 2; i++) printf("-");

    for (i = 0; i < pGame->rows; i++) {
        printf("\n|");

        for (j = 0; j < pGame->cols; j++) {
            printf("%c", pGame->dashboard[i][j]);
        }

        printf("|");
    }

    printf("\n");
    for (i = 0; i < pGame->cols + 2; i++) printf("-");
}

void setDashboardCenter(TGame* pGame) {
    int row = pGame->rows / 2;
    int col = pGame->cols / 2;

    pGame->center[0] = row;
    pGame->center[1] = col;
}

void startGameByConsole(TGame* pGame, int maxGeneration, int delayBetweenGenerations) {
    int generation = 0;
    int isToInfinity = maxGeneration == INT_MAX;

    pGame->generation = 0;
    pGame->maximumGeneration = maxGeneration;
    pGame->delayBetweenGenerations = delayBetweenGenerations;

    system("cls");
    printGameByConsole(pGame);
    if (generation == maxGeneration) return;
    sleep(delayBetweenGenerations);

    while (isToInfinity || generation < maxGeneration) {
        generateNextGeneration(pGame);

        if (generation != INT_MAX) {
            generation++;
            pGame->generation = generation;
        };

        system("cls");
        printGameByConsole(pGame);
        if (generation != maxGeneration) sleep(delayBetweenGenerations);
    }
}