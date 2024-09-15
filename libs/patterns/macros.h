
#ifndef PATTERNS_MACROS_H_INCLUDED
#define PATTERNS_MACROS_H_INCLUDED

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
 * @def PATTERN_ROWS
 * @brief Defines the number of rows in a 2D array pattern.
 *
 * This macro is used to define the number of rows in a 2D array pattern.
 * It is typically used in conjunction with the `PATTERN_COLS` macro to define
 * the size of a pattern.
 *
 * @warning The value of `PATTERN_ROWS` should be a positive integer.
 */
#define PATTERN_ROWS 13

/**
 * @def PATTERN_COLS
 * @brief Defines the number of columns in a 2D array pattern.
 *
 * This macro is used to define the number of columns in a 2D array pattern.
 * It is typically used in conjunction with the `PATTERN_ROWS` macro to define
 * the size of a pattern.
 *
 * @warning The value of `PATTERN_COLS` should be a positive integer.
 */
#define PATTERN_COLS 36

#endif  // PATTERNS_MACROS_H_INCLUDED
