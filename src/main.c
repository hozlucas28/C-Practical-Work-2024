#include "../libs/main.h"

#include "stdio.h"

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
    int invalidPattern;

    char* requestedPattern;

    game.dashboard = dashboard;
    game.rows = rows;
    game.cols = cols;
    game.cellsAlive = cellAlive;
    game.cellsDead = cellDead;

    fillDashboard(&game, 0);

    do {
        requestedPattern = getUserInputStr(
            "> Which pattern do you want "
            "('Glider','Toad', 'Press', or 'Glider cannon')? ",
            "> Invalid pattern! Try again...", 50, &validatePattern);
        printf("> Pattern received: '%s'", requestedPattern);

        invalidPattern = 0;

        if (strcmpi(requestedPattern, "GLIDER") == 0)
            gliderPattern(dashboard);
        else if (strcmpi(requestedPattern, "TOAD") == 0)
            toadPattern(dashboard);
        else if (strcmpi(requestedPattern, "PRESS") == 0)
            pressPattern(dashboard);
        else if (strcmpi(requestedPattern, "GLIDER CANNON") == 0)
            gliderCannonPattern(dashboard);
        else {
            puts("INVALID PATTERN, try again... :");
            invalidPattern = 1;
        }

    } while (invalidPattern);

    return 0;
}