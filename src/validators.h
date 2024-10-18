#ifndef SRC_VALIDATORS_H_INCLUDED
#define SRC_VALIDATORS_H_INCLUDED

/**
 * @brief Validates a number of rows.
 *
 * This function checks if a provided number of rows is within an acceptable range.
 * It ensures that the number of rows meets the required criteria for further processing.
 *
 * @param rows The number of rows to be validated.
 *
 * @return Returns `1` if the number of rows is valid, otherwise returns `0`.
 */
unsigned char validateRows(const int rows);

/**
 * @brief Validates a number of cols.
 *
 * This function checks if a provided number of cols is within an acceptable range.
 * It ensures that the number of cols meets the required criteria for further processing.
 *
 * @param cols The number of cols to be validated.
 *
 * @return Returns `1` if the number of cols is valid, otherwise returns `0`.
 */
unsigned char validateCols(const int cols);

/**
 * @brief Validates a initial state file path.
 *
 * This function checks if a file path is valid to be an initial state file.
 * It ensures that the file extension matches `csv`, or `txt`.
 *
 * @param filePath The file path to be validated.
 *
 * @return Returns `1` if the file path is valid, otherwise returns `0`.
 */
unsigned char validateInitialStateFile(const char* filePath);

#endif  // SRC_VALIDATORS_H_INCLUDED
