#ifndef VALIDATORS_H_INCLUDED
#define VALIDATORS_H_INCLUDED

/**
 * @brief Validates the pattern of user input.
 *
 * This function checks if the user input matches `glider`, `toad`, `press`, or
 * `glider cannon` pattern. The comparison is case insensitive.
 *
 * @param userInput The user input to be validated.
 *
 * @return 1 if the pattern is valid, 0 otherwise.
 */
int validatePattern(char* userInput);

#endif  // VALIDATORS_H_INCLUDED
