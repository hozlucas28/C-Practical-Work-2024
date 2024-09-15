
#ifndef VALIDATORS_H_INCLUDED
#define VALIDATORS_H_INCLUDED

/**
 * @brief Validates a delay.
 *
 * This function checks if a provided delay is between the minimum number, and the
 * maximum number for a delay in milliseconds.
 *
 * @param delay The delay to be validated.
 *
 * @return 1 if the delay is valid, 0 otherwise.
 */
int validateDelay(char* delay);

/**
 * @brief Validates a generation.
 *
 * This function checks if a provided generation string is between the minimum number, and the
 * maximum number for a generation.
 *
 * @param generation The generation to be validated.
 *
 * @return 1 if the generation is valid, 0 otherwise.
 */
int validateGeneration(char* generation);

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

// TODO: Documentation
int validatePlatform(char* platform);

#endif  // VALIDATORS_H_INCLUDED
