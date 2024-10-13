
#ifndef SRC_STRUCTS_H_INCLUDED
#define SRC_STRUCTS_H_INCLUDED

// TODO: Documentation
typedef struct {
    int dashboardRows;
    int dashboardCols;
    char* pattern;
    int maximumGeneration;
    int delay;
    char* platform;
    char* initialStateFile;
} TMainArguments;

#endif  // SRC_STRUCTS_H_INCLUDED