
#include "./utilities.h"

#include <stdio.h>
#include <string.h>

#include "../libs/main.h"
#include "./macros.h"
#include "./sdl/main.h"
#include "./validators.h"

void getMainArguments(TMainArguments* pMainArguments, const int argc, char* argv[]) {
    size_t i;

    char* argumentName;
    char* argumentValue;
    char* sep;

    int argumentValueInt;

    for (i = 1; i < argc; i++) {
        argumentName = *(argv + i);
        sep = strrchr(argumentName, '=');
        if (sep == NULL) continue;

        argumentValue = sep + 1;
        *sep = '\0';

        if (strcmp(argumentName, "--dashboard-rows") == 0) {
            sscanf(argumentValue, "%d", &argumentValueInt);
            if (validateRows(argumentValueInt)) pMainArguments->dashboardRows = argumentValueInt;

        } else if (strcmp(argumentName, "--dashboard-cols") == 0) {
            sscanf(argumentValue, "%d", &argumentValueInt);
            if (validateCols(argumentValueInt)) pMainArguments->dashboardCols = argumentValueInt;

        } else if (strcmp(argumentName, "--pattern") == 0) {
            if (validatePattern(argumentValue)) pMainArguments->pattern = argumentValue;

        } else if (strcmp(argumentName, "--maximum-generation") == 0) {
            if (validateGeneration(argumentValue)) {
                sscanf(argumentValue, "%d", &argumentValueInt);
                pMainArguments->maximumGeneration = argumentValueInt;
            };

        } else if (strcmp(argumentName, "--delay") == 0) {
            if (validateDelay(argumentValue)) {
                sscanf(argumentValue, "%d", &argumentValueInt);
                pMainArguments->delay = argumentValueInt;
            };

        } else if (strcmp(argumentName, "--platform") == 0) {
            if (validatePlatform(argumentValue)) pMainArguments->platform = argumentValue;

        } else if (strcmp(argumentName, "--initial-state-file") == 0) {
            if (validateInitialStateFile(argumentValue))
                pMainArguments->initialStateFile = argumentValue;
        };
    }
}

void setDefaultMainArguments(TMainArguments* pMainArguments) {
    int screenWidth;
    int screenHeight;

    if (!getScreenResolution(&screenWidth, &screenHeight)) {
        screenWidth = 640;
        screenHeight = 360;
    };

    pMainArguments->dashboardRows = (screenHeight / CELL_SIZE) * 0.93;
    pMainArguments->dashboardCols = (screenWidth / CELL_SIZE) * 0.99;
    pMainArguments->pattern = "";
    pMainArguments->maximumGeneration = 0;
    pMainArguments->delay = 0;
    pMainArguments->platform = "";
    pMainArguments->initialStateFile = "";
}
