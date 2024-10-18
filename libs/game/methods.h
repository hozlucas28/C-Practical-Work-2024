
#ifndef LIBS_GAME_METHODS_H_INCLUDED
#define LIBS_GAME_METHODS_H_INCLUDED

#include "../patterns/main.h"
#include "./structs.h"

/**
 * @brief Counts the number of alive neighbors around a given position inside the `dashboard` field
 * of a Conway's Game of Life structure.
 *
 * This function iterates through the cells within a specified radius around the given cell
 * (excluding the cell itself) and counts how many of those cells are alive.
 *
 * @param pGame Pointer to the Conway's Game of Life structure.
 * @param row Row index of the cell.
 * @param col Column index of the cell.
 * @param radius Radius around the cell to check for alive neighbors.
 *
 * @return The number of alive neighbors around the specified cell.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
int countAliveNeighbors(TGame* pGame, const int row, const int col, const int radius);

/**
 * @brief Draws a specified pattern on a Conway's Game of Life board.
 *
 * @param pGame Pointer to the Conway's Game of Life structure where the pattern will be drawn.
 * @param pattern Pattern to be drawn.
 *
 * @warning The pattern must be `glider`, `toad`, `press`, or `glider cannon`.
 */
void drawPattern(TGame* pGame, const char* pattern);

/**
 * @brief Draws a specified pattern on a Conway's Game of Life board.
 *
 * @param pGame Pointer to the Conway's Game of Life structure where the pattern will be drawn.
 * @param pPattern Pointer to pattern structure to be drawn.
 *
 * @warning This functions is intended for internal use only and should not be used outside of this
 * library.
 */
void drawPatternInDashboard(TGame* pGame, TPattern* pPattern);

/**
 * @brief Fills the dashboard of a Conway's Game of Life structure with a
 * specified value.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 * @param with The value to fill the dashboard with.
 *
 * @warning This function assumes that `pGame` has been
 * properly initialized.
 */
void fillDashboard(TGame* pGame, const char with);

/**
 * @brief Generates the next generation of a Conway's Game of Life.
 *
 * This function updates the `dashboard` field inside a Conway's Game of Life structure to the next
 * generation based on the current state.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void generateNextGeneration(TGame* pGame);

/**
 * @brief Prints the dashboard of a Conway's Game of Life structure by console.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void printDashboardByConsole(TGame* pGame);

/**
 * @brief Prints a Conway's Game of Life by console.
 *
 * This function takes a pointer to a Conway's Game of Life structure and prints its details
 * to the console.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void printGameByConsole(TGame* pGame);

/**
 * @brief Sets the center of a Conway's Game of Life structure.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized with valid `rows` and
 * `cols` field values.
 */
void setDashboardCenter(TGame* pGame);

/**
 * @brief Starts a Conway's Game of Life game using the console as the output.
 *
 * @param pGame Pointer to a Conway's Game of Life structure.
 * @param maxGeneration Maximum number of generations.
 * @param delayBetweenGenerations Delay in milliseconds between each generation.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void startGameByConsole(TGame* pGame, const int maxGeneration, const int delayBetweenGenerations);

#endif  // LIBS_GAME_MAIN_H_INCLUDED