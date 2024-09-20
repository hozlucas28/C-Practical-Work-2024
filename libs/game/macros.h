
#ifndef GAME_MACROS_H_INCLUDED
#define GAME_MACROS_H_INCLUDED

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
 * @def ALIVE_CELL
 * @brief Represents a live cell.
 *
 * @warning The value of `ALIVE_CELL` must be a single character.
 */
#define ALIVE_CELL 'o'

/**
 * @def ALIVE_CELL_NG
 * @brief Represents a cell that is going to be alive in the next generation.
 *
 * @warning The value of `ALIVE_CELL_NG` must be a single character and must not be equal to
 * `ALIVE_CELL`, `DEAD_CELL`, or `DEAD_CELL_NG` macros.
 */
#define ALIVE_CELL_NG '1'

/**
 * @def DEAD_CELL
 * @brief Represents a dead cell.
 *
 * @warning The value of `DEAD_CELL` must be a single character.
 */
#define DEAD_CELL ' '

/**
 * @def DEAD_CELL_NG
 * @brief Represents a cell that is going to be dead in the next generation.
 *
 * @warning The value of `DEAD_CELL_NG` must be a single character and must not be equal to
 * `ALIVE_CELL`, `ALIVE_CELL_NG`, or `DEAD_CELL` macros.
 */
#define DEAD_CELL_NG '0'

/**
 * @def NEIGHBORHOOD_RADIUS
 * @brief Defines the radius of the neighborhood.
 *
 * @warning The value of `NEIGHBORHOOD_RADIUS` must be greater or equal to 1.
 */
#define NEIGHBORHOOD_RADIUS 1

#endif  // GAME_MACROS_H_INCLUDED
