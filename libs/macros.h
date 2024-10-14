
#ifndef LIBS_MACROS_H_INCLUDED
#define LIBS_MACROS_H_INCLUDED

/**
 * @def MAX
 * @brief Returns the maximum value between two values.
 *
 * @warning The value of `a` and `b` parameters must be an integer or float.
 */
#define MAX(a, b) a > b ? a : b;

/**
 * @def MIN
 * @brief Returns the minimum value between two values.
 *
 * @warning The value of `a` and `b` parameters must be an integer or float.
 */
#define MIN(a, b) a > b ? b : a;

/**
 * @def MAXIMUM_DELAY
 * @brief Defines the maximum delay in milliseconds.
 *
 * This macro is used to define the maximum delay for a delay input.
 * It is typically used in conjunction with the `MINIMUM_DELAY`.
 *
 * @warning The value of `MAXIMUM_DELAY` must be a positive integer.
 */
#define MAXIMUM_DELAY 1000

/**
 * @def MINIMUM_DELAY
 * @brief Defines the minimum delay in milliseconds.
 *
 * This macro is used to define the minimum delay for a delay input.
 * It is typically used in conjunction with the `MAXIMUM_DELAY`.
 *
 * @warning The value of `MINIMUM_DELAY` must be a positive integer.
 */
#define MINIMUM_DELAY 0

#endif  // LIBS_MACROS_H_INCLUDED
