
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "./macros.h"
#include "./utilities.h"

int validateDelay(char* delay) {
    int i;
    int delayInt;
    int delayLength = strlen(delay);

    for (i = 0; i < delayLength; i++) {
        if (!isdigit(*(delay + i))) return 0;
    }

    sscanf(delay, "%d", &delayInt);
    return delayInt >= MINIMUM_DELAY && delayInt <= MAXIMUM_DELAY;
}

int validateGeneration(char* generation) {
    int i;
    int generationInt;
    int generationLength = strlen(generation);

    for (i = 0; i < generationLength; i++) {
        if (*(generation + i) != '-' && !isdigit(*(generation + i))) return 0;
    }

    sscanf(generation, "%d", &generationInt);
    return generationInt >= INT_MIN && generationInt <= INT_MAX;
}

int validatePattern(char* userInput) {
    char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(userInput, options, 4);
}

int validatePlatform(char* userInput) {
    char* options[] = {"console", "simple directmedia layer (sdl)", "simple directmedia layer",
                       "sdl"};
    return isStrIn(userInput, options, 4);
}