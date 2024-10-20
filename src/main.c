#include "../libs/main.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "./sdl/main.h"
#include "./structs.h"
#include "./utilities.h"

int main(const int argc, char* argv[]) {
    TMainArguments mainArguments;

    TGame game;

    int rows;
    int cols;
    char** dashboard;

    char* requestedPattern;
    char* maxGeneration;
    char* delayBetweenGenerations;
    char delayBetweenGenerationsMsg[120];
    char* platformSelected;

    int maxGenerationInt;
    int delayBetweenGenerationsInt;

    setDefaultMainArguments(&mainArguments);
    getMainArguments(&mainArguments, argc, argv);

    rows = mainArguments.dashboardRows;
    cols = mainArguments.dashboardCols;

    /* ----------------------------- Request Pattern ---------------------------- */

    if (*mainArguments.initialStateFile == '\0') {
        dashboard = new2DArray(rows, cols);

        game.dashboard = dashboard;
        game.rows = rows;
        game.cols = cols;
        game.cellsAlive = 0;
        game.cellsDead = cols * rows;
        game.generation = 0;

        setDashboardCenter(&game);

        fillDashboard(&game, DEAD_CELL);

        if (*mainArguments.pattern == '\0') {
            requestedPattern = getUserInputStr(
                "> Which pattern do you want? ('Glider','Toad', 'Press', or 'Glider cannon'): ",
                "> Invalid pattern! Try again...", 50, &validatePattern);

            printf("> Pattern received: '%s'.\n\n", requestedPattern);

            drawPattern(&game, requestedPattern);

            free(requestedPattern);
        } else {
            requestedPattern = mainArguments.pattern;

            printf("> Pattern received: '%s'.\n\n", requestedPattern);

            drawPattern(&game, requestedPattern);
        };
    } else {
        /* --------------------------- Draw Initial State --------------------------- */

        if (!setDashboardFromFile(mainArguments.initialStateFile, &game, rows, cols)) {
            printf(
                "> An error occurred on set the initial state of the dashboard! Please check the "
                "file path with the initial state (received %s) and it's content.\n",
                mainArguments.initialStateFile);

            exit(EXIT_FAILURE);
        }
    }

    /* ----------------------- Request Maximum Generation ----------------------- */

    if (mainArguments.maximumGeneration == 0) {
        maxGeneration = getUserInputStr(
            "> Which is maximum generation do you want? (a negative number is equal to infinity): ",
            "> Invalid generation! Try again...", 10, &validateGeneration);

        sscanf(maxGeneration, "%d", &maxGenerationInt);

        if (maxGenerationInt < 0) {
            free(maxGeneration);
            maxGeneration = "infinity";
            maxGenerationInt = INT_MAX;
        };

        printf("> Maximum generation received: %s.\n\n", maxGeneration);

        if (maxGenerationInt != INT_MAX) free(maxGeneration);
    } else {
        maxGenerationInt = mainArguments.maximumGeneration;

        if (maxGenerationInt < 0) {
            maxGeneration = "infinity";
            maxGenerationInt = INT_MAX;

            printf("> Maximum generation received: %s.\n\n", maxGeneration);
        } else {
            printf("> Maximum generation received: %d.\n\n", maxGenerationInt);
        }
    };

    /* ------------------------------ Request Delay ----------------------------- */

    if (mainArguments.delay == 0) {
        sprintf(
            delayBetweenGenerationsMsg,
            "> What should be the milliseconds delay between generations? (must be between %d and "
            "%d, both included): ",
            MINIMUM_DELAY, MAXIMUM_DELAY);

        delayBetweenGenerations = getUserInputStr(
            delayBetweenGenerationsMsg, "> Invalid delay! Try again...", 5, &validateDelay);

        sscanf(delayBetweenGenerations, "%d", &delayBetweenGenerationsInt);

        printf("> Delay received: %s milliseconds.\n\n", delayBetweenGenerations);

        free(delayBetweenGenerations);
    } else {
        delayBetweenGenerationsInt = mainArguments.delay;

        printf("> Delay received: %d milliseconds.\n\n", delayBetweenGenerationsInt);
    }

    /* ---------------------------- Request Platform ---------------------------- */

    if (*mainArguments.platform == '\0') {
        platformSelected = getUserInputStr(
            "> In which platform do you want to start the Conway's Game of Life game? (console, or "
            "Simple DirectMedia Layer (SDL)): ",
            "> Invalid option! Try again...", 32, &validatePlatform);

        printf("> Platform selected: '%s'.\n", platformSelected);

        if (strcmpi(platformSelected, "console") == 0) {
            free(platformSelected);
            startGameByConsole(&game, maxGenerationInt, delayBetweenGenerationsInt);
            destroy2DArray(game.dashboard, game.rows, game.cols);
            return 0;
        }

        free(platformSelected);
    } else {
        platformSelected = mainArguments.platform;

        printf("> Platform selected: '%s'.\n", platformSelected);

        if (strcmpi(platformSelected, "console") == 0) {
            startGameByConsole(&game, maxGenerationInt, delayBetweenGenerationsInt);
            destroy2DArray(game.dashboard, game.rows, game.cols);
            return 0;
        }
    }

    startGameBySDL(&game, maxGenerationInt, delayBetweenGenerationsInt);
    destroy2DArray(game.dashboard, game.rows, game.cols);

    return 0;
}
