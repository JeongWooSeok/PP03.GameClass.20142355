#include "Game.h"

bool Game::init(const char*title, int xpos, int yops, int width, int height, bool fullscree)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow("Wanna go home? Keep up pal.",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1600, 900, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
	}
	else {
		return 1;
	}
	SDL_SetRenderDrawColor(m_pRenderer, 125, 125, 125, 255);
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
	SDL_Delay(2000);
	SDL_Quit();
	return 0;

	return true;
}
	void Game::render()
	{
		SDL_RenderClear(m_pRenderer);
		SDL_RenderPresent(m_pRenderer);
	}

	void Game::clean()
	{
		std::cout<< "cleaning game\n";
		SDL_DestroyWindow(m_pWindow);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_Quit();
	}

	void Game::handleEvents()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				m_bRunning = false;
			break;
			default:
			break;
			}
		}
	}
