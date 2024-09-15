
#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

/**
 * @def DASHBOARD_ROWS
 * @brief Defines the number of rows in a grid.
 *
 * This macro is used to define the number of rows in a grid.
 * It is typically used in conjunction with the `DASHBOARD_COLS` macro to define
 * the size of a grid.
 *
 * @warning The value of `DASHBOARD_ROWS` must be a positive integer.
 */
#define DASHBOARD_ROWS 56

/**
 * @def DASHBOARD_COLS
 * @brief Defines the number of columns in a grid.
 *
 * This macro is used to define the number of columns in a grid.
 * It is typically used in conjunction with the `DASHBOARD_ROWS` macro to define
 * the size of a grid.
 *
 * @warning The value of `DASHBOARD_COLS` must be a positive integer.
 */
#define DASHBOARD_COLS 110

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

/**
 * @def NEIGHBORHOOD_RADIUS
 * @brief Defines the radius of the neighborhood.
 *
 * @warning The value of `NEIGHBORHOOD_RADIUS` must be greater or equal to 1.
 */
#define NEIGHBORHOOD_RADIUS 1

#endif  // MACROS_H_INCLUDED
