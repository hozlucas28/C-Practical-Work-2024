
#ifndef SRC_UTILITIES_H_INCLUDED
#define SRC_UTILITIES_H_INCLUDED

#include "./structs.h"

/**
 * @brief Retrieves and processes the main arguments of the application.
 *
 * This function takes the command-line arguments passed to the application,
 * processes them, and stores the relevant information in a structure. It
 * ensures that the arguments are correctly parsed and validated.
 *
 * @param pMainArguments Pointer to a `TMainArguments` structure where the
 *                       processed arguments will be stored.
 * @param argc           Number of command-line arguments.
 * @param argv           Array with the command-line arguments.
 */
void getMainArguments(TMainArguments* pMainArguments, const int argc, char* argv[]);

/**
 * @brief Sets the default values for the main arguments of the application.
 *
 * This function initializes the provided structure with default values.
 * It ensures that all necessary fields are set to their initial states.
 *
 * @param pMainArguments Pointer to a `TMainArguments` structure that will be initialized
 *                       with default values.
 */
void setDefaultMainArguments(TMainArguments* pMainArguments);

#endif  // SRC_UTILITIES_H_INCLUDED
