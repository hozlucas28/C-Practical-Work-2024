#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "macros.h"

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
    int (*dashboard)[COLS]; /** Board (2D array) in which the cells moves. */
    int rows;               /** Number of rows in `dashboard`. */
    int cols;               /** Number of columns in `dashboard`. */
    int cellsAlive;         /** Number of alive cells. */
    int cellsDead;          /** Number of dead cells. */
} TGame;

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
void fillDashboard(TGame* pGame, int with);

/**
 * @brief Gets user input as a string.
 *
 * This function prompts the user with a message and retrieves their input as a
 * string. The user's input is validated using the provided validator function.
 *
 * @param message The message to display as a prompt to the user.
 * @param onInvalidMessage The message to display when the user input is
 * invalid.
 * @param strLength The maximum length of the string to be inputted by the user.
 * @param validator A function pointer to a validator function that takes a
 * string as input and returns an integer. The validator function should return
 * 1 if the input is valid, and 0 otherwise.
 *
 * @return A pointer to the string entered by the user.
 */
char* getUserInputStr(char* message, char* onInvalidMessage, int strLength,
                      int (*validator)(char* userInput));

/**
 * @brief Checks if a string is present in an array of strings.
 *
 * This function checks if a given string is present in an array of strings.
 *
 * @param str The string to search for.
 * @param arr The array of strings to search in.
 * @param arrLength The arrLength of the array.
 *
 * @return 1 if the string is found in the array, 0 otherwise.
 */
int isStrIn(char* str, char* arr[], int arrLength);

/**
 * @brief Prints the dashboard of a Conway's Game of Life structure by console.
 *
 * @param pGame A pointer to the Conway's Game of Life structure.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
void printDashboardByConsole(TGame* pGame);

/**
 * @brief Compares two strings case-insensitively.
 *
 * This function compares two strings case-insensitively and returns an integer
 * indicating their relative order. The comparison is based on the ASCII values
 * of the characters in the strings.
 *
 * @param str01 The first string to compare.
 * @param str02 The second string to compare.
 *
 * @return An integer less than zero if str01 is less than str02, zero if str01
 * matches str02, or greater than zero if str01 is greater than str02.
 *
 * @warning This function assumes that the input strings are null-terminated.
 */
int strcmpi(const char* str01, const char* str02);

/**
 * @brief Trims leading and trailing whitespace characters from a string.
 *
 * This function trims leading and trailing whitespace characters from a string
 * by modifying the string in-place.
 *
 * @param str The string to trim.
 *
 * @warning This function assumes that the input string is null-terminated.
 */
void trimStr(char* str);

/**
 * @brief Trims leading whitespace characters from a string.
 *
 * This function trims leading whitespace characters from a string by modifying
 * the string in-place.
 *
 * @param str The string to trim.
 *
 * @warning This function assumes that the input string is null-terminated.
 */
void trimLeftStr(char* str);

/**
 * @brief Trims trailing whitespace characters from a string.
 *
 * This function trims trailing whitespace characters from a string by modifying
 * the string in-place.
 *
 * @param str The string to trim.
 *
 * @warning This function assumes that the input string is null-terminated.
 */
void trimRightStr(char* str);

// TODO: Create a function to format an array of strings to a string...
// conjunction, or disjunction.

#endif  // UTILITIES_H_INCLUDED
