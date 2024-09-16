#include "./methods.h"

#include "../../libs/main.h"

#ifdef __MINGW32__
#define SDL_MAIN_HANDLED
#include <SDL_main.h>
#endif

#include <SDL.h>
#include <stdio.h>

int startGameBySDL(TGame* pGame, int maxGeneration, int delayBetweenGenerations) {
    int i;
    int j;

    int cellSize = 10;
    int generation = 0;
    int isToInfinity = maxGeneration == INT_MAX;
    int userRequestClose = 0;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;
    SDL_Rect fillRect;

    // Window configuration
    char windowCaption[256];
    int windowWidth = cellSize * (pGame->cols + 2);
    int windowHeight = cellSize * (pGame->rows + 2);
    Uint32 windowFlags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED;

    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("\n> SDL could not initialize!");
        printf("\n> SDL_Error: %s", SDL_GetError());
        return 0;
    }

    // Create the window
    window = SDL_CreateWindow("Conway's Game of Life", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, windowFlags);

    if (!window) {
        SDL_Log("\n> Error on window creation!");
        printf("\n> SDL_Error: %s", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    // Create the display
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("\n> Error on renderer creation!");
        printf("\n> SDL_Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 0;
    }

    pGame->generation = 0;
    pGame->maximumGeneration = maxGeneration;
    pGame->delayBetweenGenerations = delayBetweenGenerations;

    // Clean the display
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(renderer);

    // Paint top limit
    for (i = 0; i < pGame->cols + 2; i++) {
        fillRect.x = cellSize * i;
        fillRect.y = 0;
        fillRect.h = cellSize;
        fillRect.w = cellSize;

        SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
    }

    // Paint left limit
    for (i = 1; i < pGame->rows + 1; i++) {
        fillRect.x = 0;
        fillRect.y = cellSize * i;
        fillRect.h = cellSize;
        fillRect.w = cellSize;

        SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
    }

    // Paint content (alive and dead cells)
    for (i = 0; i < pGame->rows; i++) {
        for (j = 0; j < pGame->cols; j++) {
            fillRect.x = cellSize * (j + 1);
            fillRect.y = cellSize * (i + 1);
            fillRect.h = cellSize;
            fillRect.w = cellSize;

            if (pGame->dashboard[i][j] == ALIVE_CELL) {
                SDL_SetRenderDrawColor(renderer, 0x66, 0xCC, 0x66, 0xFF);
                SDL_RenderFillRect(renderer, &fillRect);
            }
        }
    }

    // Paint right limit
    for (i = 1; i < pGame->rows + 1; i++) {
        fillRect.x = cellSize * (pGame->cols + 1);
        fillRect.y = cellSize * i;
        fillRect.h = cellSize;
        fillRect.w = cellSize;

        SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
    }

    // Paint down limit
    for (i = 0; i < pGame->cols + 2; i++) {
        fillRect.x = cellSize * i;
        fillRect.y = cellSize * (pGame->rows + 1);
        fillRect.h = cellSize;
        fillRect.w = cellSize;

        SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
        SDL_RenderFillRect(renderer, &fillRect);
    }

    // Set window title
    sprintf(windowCaption,
            "Conway's Game of Life  |   Alive cells: %10d  |   Dead cells: %10d  |   "
            "Generation: %10d  |   Maximum generation: %10d  |   Delay between generations: "
            "%10d ms  |",
            pGame->cellsAlive, pGame->cellsDead, pGame->generation, pGame->maximumGeneration,
            pGame->delayBetweenGenerations);

    SDL_SetWindowTitle(window, windowCaption);

    // Render the display
    SDL_RenderPresent(renderer);
    SDL_Delay(delayBetweenGenerations);

    // Close SDL if the generation is equal to zero
    if (generation == maxGeneration) {
        // Wait until the user request to close the window
        while (!userRequestClose) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) userRequestClose = 1;
            }
            if (userRequestClose) break;

            SDL_Delay(50);
        }

        // Destroy display and window, and close SDL
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();

        return 1;
    };

    SDL_RaiseWindow(window);

    while (!userRequestClose) {
        // Break loop if the user request to close the window
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) userRequestClose = 1;
        }
        if (userRequestClose) break;

        // Prevent window close when the current generation reaches the maximum generation
        if (!isToInfinity && generation >= maxGeneration) {
            SDL_Delay(50);
            continue;
        };

        generateNextGeneration(pGame);

        // Prevent generation overflow
        if (generation != INT_MAX) {
            generation++;
            pGame->generation = generation;
        };

        // Clean the display
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        // Paint top limit
        for (i = 0; i < pGame->cols + 2; i++) {
            fillRect.x = cellSize * i;
            fillRect.y = 0;
            fillRect.h = cellSize;
            fillRect.w = cellSize;

            SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
            SDL_RenderFillRect(renderer, &fillRect);
        }

        // Paint left limit
        for (i = 1; i < pGame->rows + 1; i++) {
            fillRect.x = 0;
            fillRect.y = cellSize * i;
            fillRect.h = cellSize;
            fillRect.w = cellSize;

            SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
            SDL_RenderFillRect(renderer, &fillRect);
        }

        // Paint content (alive and dead cells)
        for (i = 0; i < pGame->rows; i++) {
            for (j = 0; j < pGame->cols; j++) {
                fillRect.x = cellSize * (j + 1);
                fillRect.y = cellSize * (i + 1);
                fillRect.h = cellSize;
                fillRect.w = cellSize;

                if (pGame->dashboard[i][j] == ALIVE_CELL) {
                    SDL_SetRenderDrawColor(renderer, 0x66, 0xCC, 0x66, 0xFF);
                    SDL_RenderFillRect(renderer, &fillRect);
                }
            }
        }

        // Paint right limit
        for (i = 1; i < pGame->rows + 1; i++) {
            fillRect.x = cellSize * (pGame->cols + 1);
            fillRect.y = cellSize * i;
            fillRect.h = cellSize;
            fillRect.w = cellSize;

            SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
            SDL_RenderFillRect(renderer, &fillRect);
        }

        // Paint down limit
        for (i = 0; i < pGame->cols + 2; i++) {
            fillRect.x = cellSize * i;
            fillRect.y = cellSize * (pGame->rows + 1);
            fillRect.h = cellSize;
            fillRect.w = cellSize;

            SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF);
            SDL_RenderFillRect(renderer, &fillRect);
        }

        // Set window title
        if (isToInfinity) {
            sprintf(
                windowCaption,
                "Conway's Game of Life  |   Alive cells: %10d  |   Dead cells: %10d  |   "
                "Generation: %10d  |   Maximum generation: %10s  |   Delay between generations: "
                "%10d ms  |",
                pGame->cellsAlive, pGame->cellsDead, pGame->generation, "infinity",
                pGame->delayBetweenGenerations);
        } else {
            sprintf(
                windowCaption,
                "Conway's Game of Life  |   Alive cells: %10d  |   Dead cells: %10d  |   "
                "Generation: %10d  |   Maximum generation: %10d  |   Delay between generations: "
                "%10d ms  |",
                pGame->cellsAlive, pGame->cellsDead, pGame->generation, pGame->maximumGeneration,
                pGame->delayBetweenGenerations);
        }

        SDL_SetWindowTitle(window, windowCaption);

        // Render the display
        SDL_RenderPresent(renderer);
        SDL_Delay(delayBetweenGenerations);
    }

    // Destroy display and window, and close SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 1;
}
