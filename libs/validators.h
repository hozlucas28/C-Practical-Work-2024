
#ifndef LIBS_VALIDATORS_H_INCLUDED
#define LIBS_VALIDATORS_H_INCLUDED

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
unsigned char validateDelay(const char* delay);

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
unsigned char validateGeneration(const char* generation);

/**
 * @brief Validates a pattern.
 *
 * This function checks if a provided pattern matches `glider`, `toad`, `press`, or
 * `glider cannon`. The comparison is case insensitive.
 *
 * @param userInput The pattern to be validated.
 *
 * @return 1 if the pattern is valid, 0 otherwise.
 */
unsigned char validatePattern(const char* pattern);

/**
 * @brief Validates a platform.
 *
 * This function checks if a provided platform matches `console`, `simple directmedia layer (sdl)`,
 * `simple directmedia layer`, or `sdl`. The comparison is case insensitive.
 *
 * @param platform The platform to be validated.
 *
 * @return 1 if the platform is valid, 0 otherwise.
 */
unsigned char validatePlatform(const char* platform);

#endif  // LIBS_VALIDATORS_H_INCLUDED
