#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

/**
 * @brief Calculates the length of a string.
 *
 * This function takes a null-terminated string as input and returns the number
 * of characters in the string, excluding the null character.
 *
 * @param str The null-terminated string for which the length needs to be
 * calculated.
 *
 * @return The length of the string.
 *
 * @warning The input string must be null-terminated, otherwise the behavior is
 * undefined.
 */
int getStrLength(char* str);

void sayhi();

#endif  // UTILITIES_H_INCLUDED
