#include "../libs/main.h"

#include "stdio.h"

// TODO: Convert `options` variable into a global variable.
int validatePattern(char* userInput) {
    char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(userInput, options, 4);
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

    // TODO: Replace `XXX` with a formatted version of `options` (global...
    // variable).
    requestedPattern =
        getUserInputStr("Which pattern do you want (XXX)? ",
                        "Invalid input! Try again...", 50, &validatePattern);
    printf("\n'%s'", requestedPattern);
    return 0;
}