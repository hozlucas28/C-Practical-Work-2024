
#ifndef PATTERNS_CONSTRUCTORS_H_INCLUDED
#define PATTERNS_CONSTRUCTORS_H_INCLUDED

#include "./structs.h"

/**
 * @brief Initializes a new glider pattern.
 *
 * This function sets up a new glider pattern in the provided TPattern structure.
 * The glider pattern is a small configuration of cells that travels across a Conway's
 * Game of Life grid.
 *
 * @param pattern Pointer to the TPattern structure to be initialized with the glider pattern.
 */
void newGliderPattern(TPattern* pattern);

/**
 * @brief Initializes a new Glider Cannon pattern.
 *
 * This function sets up a Glider Cannon pattern in the provided pattern structure.
 * The Glider Cannon is a pattern that periodically produces gliders.
 *
 * @param pattern Pointer to the pattern structure to be initialized with the Glider Cannon
 * pattern.
 */
void newGliderCannonPattern(TPattern* pattern);

// TODO: Documentation
void newPressPattern(TPattern* pattern);

// TODO: Documentation
void newToadPattern(TPattern* pattern);

#endif  // PATTERNS_CONSTRUCTORS_H_INCLUDED
