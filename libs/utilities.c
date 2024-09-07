#include <stdio.h>

int getStrLength(char* str) {
    int length = 0;

    while (*str != '\0') {
        length++;
        str++;
    };

    return length;
}

void sayhi() { printf("hello guys"); }
