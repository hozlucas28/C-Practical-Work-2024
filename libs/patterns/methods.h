
#ifndef PATTERNS_METHODS_H_INCLUDED
#define PATTERNS_METHODS_H_INCLUDED

#include "./structs.h"

/**
 * @brief Fills the `arr` field of a pattern structure with a specified value.
 *
 * @param pPattern A pointer to the pattern structure.
 * @param with The value to fill the `arr` field.
 *
 * @warning This function assumes that `pPattern` has been properly initialized.
 */
void fillPattern(TPattern* pPattern, char with);

// TODO: Documentation
void printPatternByConsole(TPattern* pPattern);

#endif  // PATTERNS_METHODS_H_INCLUDED
