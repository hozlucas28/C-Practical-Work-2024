
#include "./methods.h"

#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "../patterns/main.h"
#include "../utilities.h"
#include "./macros.h"
#include "./structs.h"

int countAliveNeighbors(TGame* pGame, const int cellRow, const int cellCol, const int radius) {
    int i;
    int j;

    const int startRow = cellRow - radius;
    const int startCol = cellCol - radius;

    const int endRow = cellRow + radius + 1;
    const int endCol = cellCol + radius + 1;

    size_t aliveNeighbors = 0;

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

void drawPattern(TGame* pGame, const char* pattern) {
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
    destroy2DArray(SPattern.arr, SPattern.rows, SPattern.cols);
}

void drawPatternInDashboard(TGame* pGame, TPattern* pPattern) {
    size_t i;
    size_t j;

    size_t pI = 0;
    size_t pJ = 0;

    int startRow;
    int startCol;

    if (pPattern->rows > pGame->rows || pPattern->cols > pGame->cols) {
        destroy2DArray(pGame->dashboard, pGame->rows, pGame->cols);

        pGame->dashboard = new2DArray(pPattern->rows, pPattern->cols);
        pGame->rows = pPattern->rows;
        pGame->cols = pPattern->cols;
        pGame->cellsDead = (pGame->rows * pGame->cols) - pGame->cellsAlive;

        setDashboardCenter(pGame);

        fillDashboard(pGame, DEAD_CELL);
    }

    startRow = pGame->center[0] - pPattern->center[0];
    startCol = pGame->center[1] - pPattern->center[1];

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

void fillDashboard(TGame* pGame, const char with) {
    size_t i;
    size_t j;

    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            pGame->dashboard[i][j] = with;
        }
    }
}

void generateNextGeneration(TGame* pGame) {
    size_t i;
    size_t j;

    size_t aliveNeighbors;

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
    size_t i;
    size_t j;

    for (i = 0; i < pGame->rows; i++) {
        printf("\n");

        for (j = 0; j < pGame->cols; j++) {
            printf("%c", pGame->dashboard[i][j]);
        }
    }
}

void printGameByConsole(TGame* pGame) {
    size_t i;
    size_t j;

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
    const int row = pGame->rows / 2;
    const int col = pGame->cols / 2;

    pGame->center[0] = row;
    pGame->center[1] = col;
}

int setDashboardFromFile(const char* filePath, TGame* pGame, const int minRows, const int minCols) {
    FILE* pf;
    TPattern pattern;

    char* line;
    const size_t lineLength = 100;

    char* row;
    char* col;
    char* sep;

    int rowInt;
    int colInt;

    int rows = minRows;
    int cols = minCols;

    int patternRows = 0;
    int patternCols = 0;

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

        patternRows = MAX(rowInt, patternRows);
        patternCols = MAX(colInt, patternCols);
    }

    rows = MAX(patternRows, rows);
    cols = MAX(patternCols, cols);

    pGame->dashboard = new2DArray(rows, cols);
    pGame->rows = rows;
    pGame->cols = cols;
    pGame->cellsAlive = 0;
    pGame->generation = 0;

    setDashboardCenter(pGame);

    fillDashboard(pGame, DEAD_CELL);

    pattern.arr = new2DArray(patternRows, patternCols);
    pattern.rows = patternRows;
    pattern.cols = patternCols;

    setPatternCenter(&pattern);

    fillPattern(&pattern, DEAD_CELL);

    rewind(pf);
    fgets(line, lineLength, pf);

    while (fgets(line, lineLength, pf)) {
        row = line;
        sep = strrchr(line, ';');
        if (sep == NULL) continue;

        *sep = '\0';
        col = sep + 1;

        sscanf(row, "%d", &rowInt);
        sscanf(col, "%d", &colInt);

        pattern.arr[rowInt - 1][colInt - 1] = ALIVE_CELL;
        pGame->cellsAlive++;
    }

    pGame->cellsDead = (cols * rows) - pGame->cellsAlive;

    drawPatternInDashboard(pGame, &pattern);
    destroy2DArray(pattern.arr, pattern.rows, pattern.cols);

    fclose(pf);
    free(line);

    return 1;
}

void startGameByConsole(TGame* pGame, const int maxGeneration, const int delayBetweenGenerations) {
    size_t generation = 0;
    unsigned char isToInfinity = maxGeneration == INT_MAX;

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
