
#ifndef SRC_STRUCTS_H_INCLUDED
#define SRC_STRUCTS_H_INCLUDED

/**
 * @struct TMainArguments
 * @brief Represents the main arguments of the application.
 *
 * This structure holds the main configuration parameters for the application.
 */
typedef struct {
    int dashboardRows;      /** Number of rows in the dashboard. */
    int dashboardCols;      /** Number of columns in the dashboard. */
    char* pattern;          /** Pattern to be drawn on the dashboard. */
    int maximumGeneration;  /** Maximum number of generations to simulate. */
    int delay;              /** Delay between generations in milliseconds. */
    char* platform;         /** Platform on which the application will be run. */
    char* initialStateFile; /** File containing the initial state of the dashboard. */
} TMainArguments;

#endif  // SRC_STRUCTS_H_INCLUDED