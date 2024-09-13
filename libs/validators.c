
#include <limits.h>
#include <stdio.h>

#include "./utilities.h"

int validateGeneration(char* generation) {
    int generationInt;
    sscanf(generation, "%d", &generationInt);
    return generationInt >= INT_MIN && generationInt <= INT_MAX;
}

int validatePattern(char* userInput) {
    char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(userInput, options, 4);
}