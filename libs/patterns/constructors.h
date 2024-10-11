
#ifndef LIBS_PATTERNS_CONSTRUCTORS_H_INCLUDED
#define LIBS_PATTERNS_CONSTRUCTORS_H_INCLUDED

#include "./structs.h"

/**
 * @brief Initializes a new Glider pattern.
 *
 * This function sets up a new Glider pattern in the provided pattern structure.
 * The Glider pattern is a pattern of cells that travels across a Conway's Game of Life grid.
 *
 * @param pattern Pointer to the pattern structure to be initialized with the glider pattern.
 */
void newGliderPattern(TPattern* pattern);

/**
 * @brief Initializes a new Glider Cannon pattern.
 *
 * This function sets up a Glider Cannon pattern in the provided pattern structure.
 * The Glider Cannon is a pattern of cells that periodically produces gliders that travels across a
 * Conway's Game of Life grid.
 *
 * @param pattern Pointer to the pattern structure to be initialized with the Glider Cannon
 * pattern.
 */
void newGliderCannonPattern(TPattern* pattern);

/**
 * @brief Initializes a new Press pattern.
 *
 * This function sets up a new Press pattern by initializing the provided pattern structure.
 * The Press is a pattern of cells that oscillates with a period of 3 generations in a Conway's Game
 * of Life grid.
 *
 * @param pattern Pointer to the pattern structure to be initialized with the Press pattern.
 */
void newPressPattern(TPattern* pattern);

/**
 * @brief Initializes a new Toad pattern.
 *
 * This function sets up a new Toad pattern by initializing the provided pattern structure.
 * The Toad is a pattern of cells that oscillates with a period of 2 generations in a Conway's Game
 * of Life grid.
 *
 * @param pattern Pointer to the pattern structure to be initialized with the Toad pattern.
 */
void newToadPattern(TPattern* pattern);

#endif  // LIBS_PATTERNS_CONSTRUCTORS_H_INCLUDED
