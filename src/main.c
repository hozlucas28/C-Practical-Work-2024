#include "../libs/main.h"

#include "stdio.h"

int validatePattern(char* userInput) {
    char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(userInput, options, 2);
}

int main() {
    TGame game;

    int dashboard[ROWS][COLS];
    int rows = ROWS;
    int cols = COLS;
    int cellAlive = 0;
    int cellDead = 0;

    char* requestedPattern;

    game.dashboard = dashboard;
    game.rows = rows;
    game.cols = cols;
    game.cellsAlive = cellAlive;
    game.cellsDead = cellDead;

    fillDashboard(&game, 0);

    requestedPattern = getUserInputStr("Which pattern do you want (XXX)? ", 100,
                                       &validatePattern);
    printf("\n'%s'", requestedPattern);
    return 0;
}