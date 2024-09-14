#include "../libs/main.h"

#include <limits.h>
#include <stdio.h>

#include "../libs/utilities.c"

int main() {
    TGame game;

    char dashboard[DASHBOARD_ROWS][DASHBOARD_COLS];
    int rows = DASHBOARD_ROWS;
    int cols = DASHBOARD_COLS;

    char* requestedPattern;
    char* maxGenerations;
    char* delayBetweenGenerations;
    char delayBetweenGenerationsMsg[120];

    int maxGenerationsInt;
    int delayBetweenGenerationsInt;

    game.dashboard = dashboard;
    game.rows = rows;
    game.cols = cols;
    game.cellsAlive = 0;
    game.cellsDead = cols * rows;
    game.generation = 0;

    setDashboardCenter(&game);
    fillDashboard(&game, DEAD_CELL);

    /* ----------------------------- Request Pattern ---------------------------- */

    requestedPattern = getUserInputStr(
        "> Which pattern do you want ('Glider','Toad', 'Press', or 'Glider cannon')? ",
        "> Invalid pattern! Try again...", 50, &validatePattern);

    printf("> Pattern received: '%s'.\n\n", requestedPattern);

    drawPattern(&game, requestedPattern);
    printDashboardByConsole(&game);

    /* ----------------------- Request Maximum Generation ----------------------- */

    maxGenerations = getUserInputStr(
        "> Which is maximum generation do you want? (a negative number is equal to infinity): ",
        "> Invalid generation! Try again...", 10, &validateGeneration);

    sscanf(maxGenerations, "%d", &maxGenerationsInt);

    if (maxGenerationsInt < 0) {
        maxGenerations = "'infinity'";
        maxGenerationsInt = INT_MAX;
    };

    printf("> Maximum generation received: %s.\n\n", maxGenerations);

    /* ------------------------------ Request Delay ----------------------------- */

    sprintf(delayBetweenGenerationsMsg,
            "> What should be the miliseconds delay between generations? (must be between %d and "
            "%d, both included): ",
            MINIMUM_DELAY, MAXIMUM_DELAY);

    delayBetweenGenerations = getUserInputStr(delayBetweenGenerationsMsg,
                                              "> Invalid delay! Try again...", 5, &validateDelay);

    sscanf(delayBetweenGenerations, "%d", &delayBetweenGenerationsInt);

    printf("> Delay received: %s miliseconds.\n", delayBetweenGenerations);

    return 0;
}
