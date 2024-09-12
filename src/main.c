#include "../libs/main.h"

#include "stdio.h"

int main() {
    TGame game;

    char dashboard[DASHBOARD_ROWS][DASHBOARD_COLS];
    int rows = DASHBOARD_ROWS;
    int cols = DASHBOARD_COLS;

    char* requestedPattern;

    game.dashboard = dashboard;
    game.rows = rows;
    game.cols = cols;
    game.cellsAlive = 0;
    game.cellsDead = cols * rows;
    game.generation = 0;

    fillDashboard(&game, DEAD_CELL);

    requestedPattern = getUserInputStr(
        "> Which pattern do you want ('Glider','Toad', 'Press', or 'Glider cannon')? ",
        "> Invalid pattern! Try again...", 50, &validatePattern);
    printf("> Pattern received: '%s'", requestedPattern);

    drawPattern(&game, requestedPattern);

    return 0;
}
