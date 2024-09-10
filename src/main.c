#include "../libs/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    int dashboard[ROWS][COLS];
    int rows = ROWS;
    int cols = COLS;
    int cellAlive;
    int cellDead;

    TGame game;

    game.dashboard = dashboard;
    game.rows = rows;
    game.cols = cols;
    game.cellAlive = cellAlive;
    game.cellDead = cellDead;

    printDashboard(&game);
    return 0;
}
