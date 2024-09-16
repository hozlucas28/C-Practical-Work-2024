
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
int countAliveNeighbors(TGame* pGame, int row, int col, int radius);

/**
 * @brief Draws a specified pattern on a Conway's Game of Life board.
 *
 * @param pGame Pointer to the Conway's Game of Life structure where the pattern will be drawn.
 * @param pattern Pattern to be drawn.
 *
 * @warning The pattern must be `glider`, `toad`, `press`, or `glider cannon`.
 */
void drawPattern(TGame* pGame, char* pattern);

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
void fillDashboard(TGame* pGame, char with);

// TODO: Documentation
void generateNextGeneration(TGame* pGame);

/**
 * @brief Prints the dashboard of a Conway's Game of Life structure by console.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void printDashboardByConsole(TGame* pGame);

// TODO: Documentation
void printGame(TGame* pGame);

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
void startGameByConsole(TGame* pGame, int maxGeneration, int delayBetweenGenerations);