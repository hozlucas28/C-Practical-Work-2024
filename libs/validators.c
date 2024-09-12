
#include "./utilities.h"

int validatePattern(char* userInput) {
    char* options[] = {"glider", "toad", "press", "glider cannon"};
    return isStrIn(userInput, options, 4);
}