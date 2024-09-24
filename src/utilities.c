
#include "./utilities.h"

#include <stdio.h>
#include <string.h>

#include "../libs/main.h"

void getMainArguments(TMainArguments* pMainArguments, int argc, char* argv[]) {
    int i;

    char argumentName[50];
    char* argumentValue;

    int argumentValueInt;

    for (i = 1; i < argc; i++) {
        argumentValue = malloc(50 * sizeof(char));
        sscanf(*(argv + i), "-- %[a-z|-] = %[-|a-z| |0-9]", argumentName, argumentValue);

        if (strcmp(argumentName, "dashboard-rows") == 0) {
            sscanf(argumentValue, "%d", &argumentValueInt);
            if (argumentValueInt > 0) pMainArguments->dashboardRows = argumentValueInt;

            free(argumentValue);

        } else if (strcmp(argumentName, "dashboard-cols") == 0) {
            sscanf(argumentValue, "%d", &argumentValueInt);
            if (argumentValueInt > 0) pMainArguments->dashboardCols = argumentValueInt;

            free(argumentValue);

        } else if (strcmp(argumentName, "pattern") == 0) {
            if (validatePattern(argumentValue)) pMainArguments->pattern = argumentValue;

        } else if (strcmp(argumentName, "maximum-generation") == 0) {
            if (validateGeneration(argumentValue)) {
                sscanf(argumentValue, "%d", &argumentValueInt);
                pMainArguments->maximumGeneration = argumentValueInt;
            }

            free(argumentValue);

        } else if (strcmp(argumentName, "delay") == 0) {
            if (validateDelay(argumentValue)) {
                sscanf(argumentValue, "%d", &argumentValueInt);
                pMainArguments->delay = argumentValueInt;
            };

            free(argumentValue);

        } else if (strcmp(argumentName, "platform") == 0) {
            if (validatePlatform(argumentValue)) pMainArguments->platform = argumentValue;

        } else {
            free(argumentValue);
        }
    }
}

void setDefaultMainArguments(TMainArguments* pMainArguments) {
    pMainArguments->dashboardRows = 0;
    pMainArguments->dashboardCols = 0;
    pMainArguments->pattern = "";
    pMainArguments->maximumGeneration = 0;
    pMainArguments->delay = 0;
    pMainArguments->platform = "";
}
