
#include "./validators.h"

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

#include "./macros.h"
#include "./utilities.h"

unsigned char validateDelay(const char* delay) {
    size_t i;
    int delayInt;
    size_t delayLength = strlen(delay);

    for (i = 0; i < delayLength; i++) {
        if (!isdigit(*(delay + i))) return 0;
    }

    sscanf(delay, "%d", &delayInt);
    return delayInt >= MINIMUM_DELAY && delayInt <= MAXIMUM_DELAY;
}

unsigned char validateGeneration(const char* generation) {
    size_t i;
    int generationInt;
    size_t generationLength = strlen(generation);

    for (i = 0; i < generationLength; i++) {
        if (*(generation + i) != '-' && !isdigit(*(generation + i))) return 0;
    }

    sscanf(generation, "%d", &generationInt);
    return generationInt >= INT_MIN && generationInt <= INT_MAX;
}

unsigned char validatePattern(const char* pattern) {
    const char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(pattern, options, 4);
}

unsigned char validatePlatform(const char* userInput) {
    const char* options[] = {"console", "simple directmedia layer (sdl)",
                             "simple directmedia layer", "sdl"};
    return isStrIn(userInput, options, 4);
}