#ifndef SDL_METHODS_H_INCLUDED
#define SDL_METHODS_H_INCLUDED

#include "../../libs/main.h"

/**
 * @brief Gets the current screen resolution.
 *
 * @param width Pointer to store the screen width.
 * @param height Pointer to store the screen height.
 *
 * @return Returns `1` if the screen resolution was successfully obtained, or `0` if it was not.
 */
int getScreenResolution(int* width, int* height);

/**
 * @brief Starts a Conway's Game of Life game using the SDL library for display.
 *
 * @param pGame Pointer to a Conway's Game of Life structure.
 * @param maxGeneration Maximum number of generations.
 * @param delayBetweenGenerations Delay in milliseconds between each generation.
 *
 * @warning This function assumes that `pGame` has been properly initialized.
 */
int startGameBySDL(TGame* pGame, int maxGeneration, int delayBetweenGenerations);

#endif  // SDL_METHODS_H_INCLUDED
