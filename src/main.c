#include "../libs/main.h"

#include "stdio.h"

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
    game.generation = 0;

    fillDashboard(&game, 0);

    requestedPattern = getUserInputStr(
        "> Which pattern do you want "
        "('Glider','Toad', 'Press', or 'Glider cannon')? ",
        "> Invalid pattern! Try again...", 50, &validatePattern);
    printf("> Pattern received: '%s'", requestedPattern);

    drawPattern(&game, requestedPattern);

    return 0;
}
