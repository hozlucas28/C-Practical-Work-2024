#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include "macros.h"

/**
 * @struct TGame
 * @brief Represents a game structure.
 *
 * This structure represents a game in which the player's moves are
 * recorded. It contains a dashboard, which is a 2D array representing the
 * game board, as well as other properties such as the number of rows and
 * columns in the dashboard, and the values to represent alive and dead cells.
 */
typedef struct {
    int (*dashboard)[COLS]; /** The game board represented as a 2D array. */
    int rows;               /** The number of rows in the game board. */
    int cols;               /** The number of columns in the game board. */
    int cellsAlive;         /** The value representing an alive cell. */
    int cellsDead;          /** The value representing a dead cell. */
} TGame;

/**
 * @brief Fills the dashboard of a game with a specified value.
 *
 * This function fills the dashboard of a game with a specified value. The
 * dashboard represents the game board where the player's moves are recorded.
 *
 * @param pGame A pointer to the game structure.
 * @param with The value to fill the dashboard with.
 *
 * @warning This function assumes that the game structure (`pGame`) has been
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
 * @param strLength The maximum length of the string to be inputted by the user.
 * @param validator A function pointer to a validator function that takes a
 * string as input and returns an integer. The validator function should return
 * 1 if the input is valid, and 0 otherwise.
 *
 * @return A pointer to the string entered by the user.
 *
 * @warning The returned string may be longer than the specified strLength if
 * the user enters more characters.
 */
char* getUserInputStr(char* message, int strLength,
                      int (*validator)(char* userInput));

/**
 * @brief Checks if a string is present in an array of strings.
 *
 * This function checks if a given string is present in an array of strings.
 *
 * @param str The string to search for.
 * @param arr The array of strings to search in.
 * @param size The size of the array.
 *
 * @return 1 if the string is found in the array, 0 otherwise.
 */
int isStrIn(char* str, char* arr[], int size);

/**
 * @brief Prints the dashboard of a game.
 *
 * This function prints the dashboard of a game, which represents the game board
 * where the player's moves are recorded.
 *
 * @param pGame A pointer to the game structure.
 *
 * @warning This function assumes that the game structure (`pGame`) has been
 * properly initialized and the dashboard has been filled with values.
 */
void printDashboard(TGame* pGame);

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
 * @return An integer less than, equal to, or greater than zero if str01 is
 * found, respectively, to be less than, to match, or be greater than str02.
 *
 * @warning This function assumes that the input strings are null-terminated.
 */
int strcmpi(const char* str01, const char* str02);

/**
 * @brief Trims leading and trailing whitespace characters from a string.
 *
 * This function trims leading and trailing whitespace characters from a string
 * by modifying the string in-place. The trimmed string will have no leading or
 * trailing whitespace characters.
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
 * the string in-place. The trimmed string will have no leading whitespace
 * characters.
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
 * the string in-place. The trimmed string will have no trailing whitespace
 * characters.
 *
 * @param str The string to trim.
 *
 * @warning This function assumes that the input string is null-terminated.
 */
void trimRightStr(char* str);

#endif  // UTILITIES_H_INCLUDED
