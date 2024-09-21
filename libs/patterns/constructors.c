
#include "./constructors.h"

#include "../game/main.h"
#include "./methods.h"
#include "./structs.h"

void newGliderPattern(TPattern* pattern) {
    pattern->rows = 3;
    pattern->cols = 3;

    pattern->arr = new2DArray(pattern->rows, pattern->cols);

    setPatternCenter(pattern);

    fillPattern(pattern, DEAD_CELL);

    pattern->arr[0][2] = ALIVE_CELL;
    pattern->arr[1][0] = ALIVE_CELL;
    pattern->arr[1][2] = ALIVE_CELL;
    pattern->arr[2][1] = ALIVE_CELL;
    pattern->arr[2][2] = ALIVE_CELL;
}

void newGliderCannonPattern(TPattern* pattern) {
    pattern->rows = 9;
    pattern->cols = 36;
    pattern->arr = new2DArray(pattern->rows, pattern->cols);

    setPatternCenter(pattern);

    fillPattern(pattern, DEAD_CELL);

    pattern->arr[4][0] = ALIVE_CELL;
    pattern->arr[5][0] = ALIVE_CELL;
    pattern->arr[4][1] = ALIVE_CELL;
    pattern->arr[5][1] = ALIVE_CELL;

    pattern->arr[4][10] = ALIVE_CELL;
    pattern->arr[5][10] = ALIVE_CELL;
    pattern->arr[6][10] = ALIVE_CELL;
    pattern->arr[7][11] = ALIVE_CELL;
    pattern->arr[8][12] = ALIVE_CELL;
    pattern->arr[8][13] = ALIVE_CELL;
    pattern->arr[7][15] = ALIVE_CELL;
    pattern->arr[5][14] = ALIVE_CELL;
    pattern->arr[3][11] = ALIVE_CELL;
    pattern->arr[2][12] = ALIVE_CELL;
    pattern->arr[2][13] = ALIVE_CELL;
    pattern->arr[3][15] = ALIVE_CELL;
    pattern->arr[4][16] = ALIVE_CELL;
    pattern->arr[5][16] = ALIVE_CELL;
    pattern->arr[6][16] = ALIVE_CELL;
    pattern->arr[5][17] = ALIVE_CELL;
    pattern->arr[4][20] = ALIVE_CELL;
    pattern->arr[3][20] = ALIVE_CELL;
    pattern->arr[2][20] = ALIVE_CELL;
    pattern->arr[4][21] = ALIVE_CELL;
    pattern->arr[3][21] = ALIVE_CELL;
    pattern->arr[2][21] = ALIVE_CELL;
    pattern->arr[5][22] = ALIVE_CELL;
    pattern->arr[1][22] = ALIVE_CELL;
    pattern->arr[1][24] = ALIVE_CELL;
    pattern->arr[0][24] = ALIVE_CELL;
    pattern->arr[5][24] = ALIVE_CELL;
    pattern->arr[6][24] = ALIVE_CELL;

    pattern->arr[3][34] = ALIVE_CELL;
    pattern->arr[2][34] = ALIVE_CELL;
    pattern->arr[3][35] = ALIVE_CELL;
    pattern->arr[2][35] = ALIVE_CELL;
}

void newPressPattern(TPattern* pattern) {
    pattern->rows = 13;
    pattern->cols = 13;
    pattern->arr = new2DArray(pattern->rows, pattern->cols);

    setPatternCenter(pattern);

    fillPattern(pattern, DEAD_CELL);

    pattern->arr[0][2] = ALIVE_CELL;
    pattern->arr[0][3] = ALIVE_CELL;
    pattern->arr[0][4] = ALIVE_CELL;
    pattern->arr[0][8] = ALIVE_CELL;
    pattern->arr[0][9] = ALIVE_CELL;
    pattern->arr[0][10] = ALIVE_CELL;

    pattern->arr[2][0] = ALIVE_CELL;
    pattern->arr[2][5] = ALIVE_CELL;
    pattern->arr[2][7] = ALIVE_CELL;
    pattern->arr[2][12] = ALIVE_CELL;

    pattern->arr[3][0] = ALIVE_CELL;
    pattern->arr[3][5] = ALIVE_CELL;
    pattern->arr[3][7] = ALIVE_CELL;
    pattern->arr[3][12] = ALIVE_CELL;

    pattern->arr[4][0] = ALIVE_CELL;
    pattern->arr[4][5] = ALIVE_CELL;
    pattern->arr[4][7] = ALIVE_CELL;
    pattern->arr[4][12] = ALIVE_CELL;

    pattern->arr[5][2] = ALIVE_CELL;
    pattern->arr[5][3] = ALIVE_CELL;
    pattern->arr[5][4] = ALIVE_CELL;
    pattern->arr[5][8] = ALIVE_CELL;
    pattern->arr[5][9] = ALIVE_CELL;
    pattern->arr[5][10] = ALIVE_CELL;

    pattern->arr[7][2] = ALIVE_CELL;
    pattern->arr[7][3] = ALIVE_CELL;
    pattern->arr[7][4] = ALIVE_CELL;
    pattern->arr[7][8] = ALIVE_CELL;
    pattern->arr[7][9] = ALIVE_CELL;
    pattern->arr[7][10] = ALIVE_CELL;

    pattern->arr[8][0] = ALIVE_CELL;
    pattern->arr[8][5] = ALIVE_CELL;
    pattern->arr[8][7] = ALIVE_CELL;
    pattern->arr[8][12] = ALIVE_CELL;

    pattern->arr[9][0] = ALIVE_CELL;
    pattern->arr[9][7] = ALIVE_CELL;
    pattern->arr[9][5] = ALIVE_CELL;
    pattern->arr[9][12] = ALIVE_CELL;

    pattern->arr[10][0] = ALIVE_CELL;
    pattern->arr[10][5] = ALIVE_CELL;
    pattern->arr[10][7] = ALIVE_CELL;
    pattern->arr[10][12] = ALIVE_CELL;

    pattern->arr[12][2] = ALIVE_CELL;
    pattern->arr[12][3] = ALIVE_CELL;
    pattern->arr[12][4] = ALIVE_CELL;
    pattern->arr[12][8] = ALIVE_CELL;
    pattern->arr[12][9] = ALIVE_CELL;
    pattern->arr[12][10] = ALIVE_CELL;
}

void newToadPattern(TPattern* pattern) {
    pattern->rows = 2;
    pattern->cols = 4;
    pattern->arr = new2DArray(pattern->rows, pattern->cols);

    setPatternCenter(pattern);

    fillPattern(pattern, DEAD_CELL);

    pattern->arr[0][1] = ALIVE_CELL;
    pattern->arr[0][2] = ALIVE_CELL;
    pattern->arr[0][3] = ALIVE_CELL;
    pattern->arr[1][0] = ALIVE_CELL;
    pattern->arr[1][1] = ALIVE_CELL;
    pattern->arr[1][2] = ALIVE_CELL;
}
