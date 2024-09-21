#include "../libs/main.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "./sdl/main.h"

int main() {
    TGame game;

    char dashboard[DASHBOARD_ROWS][DASHBOARD_COLS];
    int rows = DASHBOARD_ROWS;
    int cols = DASHBOARD_COLS;

    char* requestedPattern;
    char* maxGeneration;
    char* delayBetweenGenerations;
    char delayBetweenGenerationsMsg[120];
    char* platformSelected;

    int maxGenerationInt;
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
        "> Which pattern do you want? ('Glider','Toad', 'Press', or 'Glider cannon'): ",
        "> Invalid pattern! Try again...", 50, &validatePattern);

    printf("> Pattern received: '%s'.\n\n", requestedPattern);

    drawPattern(&game, requestedPattern);

    free(requestedPattern);

    /* ----------------------- Request Maximum Generation ----------------------- */

    maxGeneration = getUserInputStr(
        "> Which is maximum generation do you want? (a negative number is equal to infinity): ",
        "> Invalid generation! Try again...", 10, &validateGeneration);

    sscanf(maxGeneration, "%d", &maxGenerationInt);

    if (maxGenerationInt < 0) {
        maxGeneration = "infinity";
        maxGenerationInt = INT_MAX;
    };

    printf("> Maximum generation received: %s.\n\n", maxGeneration);

    free(maxGeneration);

    /* ------------------------------ Request Delay ----------------------------- */

    sprintf(delayBetweenGenerationsMsg,
            "> What should be the milliseconds delay between generations? (must be between %d and "
            "%d, both included): ",
            MINIMUM_DELAY, MAXIMUM_DELAY);

    delayBetweenGenerations = getUserInputStr(delayBetweenGenerationsMsg,
                                              "> Invalid delay! Try again...", 5, &validateDelay);

    sscanf(delayBetweenGenerations, "%d", &delayBetweenGenerationsInt);

    printf("> Delay received: %s milliseconds.\n\n", delayBetweenGenerations);

    free(delayBetweenGenerations);

    /* ---------------------------- Request Platform ---------------------------- */

    platformSelected = getUserInputStr(
        "> In which platform do you want to start the Conway's Game of Life game? (console, or "
        "Simple DirectMedia Layer (SDL)): ",
        "> Invalid option! Try again...", 32, &validatePlatform);

    printf("> Platform selected: '%s'.\n", platformSelected);

    if (strcmpi(platformSelected, "console") == 0) {
        free(platformSelected);
        startGameByConsole(&game, maxGenerationInt, delayBetweenGenerationsInt);
        return 0;
    }

    free(platformSelected);
    startGameBySDL(&game, maxGenerationInt, delayBetweenGenerationsInt);

    return 0;
}
