
#include "../main.h"

#ifndef GAME_STRUCTS_H_INCLUDED
#define GAME_STRUCTS_H_INCLUDED

/**
 * @struct TGame
 * @brief Represents a Conway's Game of Life structure.
 *
 * This structure represents a Conway's Game of Life in which the cells moves
 * are recorded. It contains a dashboard, which is a 2D array representing the
 * game board, as well as other properties such as the number of rows and
 * columns in the dashboard, and the values to represent alive and dead cells.
 */
typedef struct {
    char (*dashboard)[DASHBOARD_COLS]; /** Board (2D array) in which the cells moves. */
    int rows;                          /** Number of rows in `dashboard`. */
    int cols;                          /** Number of columns in `dashboard`. */
    int center[2];  /** Array (row, and column) representing the center of the `dashboard`. */
    int cellsAlive; /** Number of alive cells. */
    int cellsDead;  /** Number of dead cells. */
    int generation; /** Represents the generation number. */
    int maximumGeneration;       /** Maximum number of generations to be processed. */
    int delayBetweenGenerations; /** Delay time in milliseconds for processed the next generation.*/
} TGame;

#endif  // GAME_STRUCTS_H_INCLUDED