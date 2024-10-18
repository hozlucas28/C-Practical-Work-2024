
#ifndef LIBS_PATTERNS_METHODS_H_INCLUDED
#define LIBS_PATTERNS_METHODS_H_INCLUDED

#include "./structs.h"

/**
 * @brief Fills the `arr` field of a pattern structure with a specified value.
 *
 * @param pPattern A pointer to the pattern structure.
 * @param with The value to fill the `arr` field.
 *
 * @warning This function assumes that `pPattern` has been properly initialized.
 */
void fillPattern(TPattern* pPattern, const char with);

/**
 * @brief Prints the `arr` field of a pattern structure by console.
 *
 * @param pPattern A pointer to the pattern structure.
 *
 * @warning This function assumes that `pPattern` has been properly initialized.
 */
void printPatternByConsole(TPattern* pPattern);

/**
 * @brief Sets the center of a pattern structure.
 *
 * @param pPattern A pointer to the pattern structure.
 *
 * @warning This function assumes that `pPattern` has been properly initialized with valid `rows`
 * and `cols` field values.
 */
void setPatternCenter(TPattern* pPattern);

#endif  // LIBS_PATTERNS_METHODS_H_INCLUDED