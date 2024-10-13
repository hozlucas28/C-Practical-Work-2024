
#include "./validators.h"

#include <strings.h>

#include "./macros.h"
#include "./sdl/methods.h"

int validateRows(int rows) {
    int maxRows;
    int screenHeight;
    int _;

    if (!getScreenResolution(&_, &screenHeight)) screenHeight = 0;
    maxRows = (screenHeight / CELL_SIZE) - 2;

    return rows > 0 && rows <= maxRows;
}

int validateCols(int cols) {
    int maxCols;
    int screenWidth;
    int _;

    if (!getScreenResolution(&screenWidth, &_)) screenWidth = 0;
    maxCols = (screenWidth / CELL_SIZE) - 2;

    return cols > 0 && cols <= maxCols;
}

int validateInitialStateFile(char* filePath) {
    char* extensions[] = {"csv", "txt"};
    char* extension = strrchr(filePath, '.');
    return extension == NULL ? 0 : isStrIn(extension + 1, extensions, 2);
}
