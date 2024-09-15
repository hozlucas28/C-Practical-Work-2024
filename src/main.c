#include "../libs/main.h"

#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "Hello World!";
    int strLength = getStrLength(str);

    printf("> The length of the string \"%s\" is %d.", str, strLength);

    return 0;
}
