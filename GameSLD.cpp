/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>

#include "D:/VS STUDIO C++/GameSLD/GameSLD/CommonFunction.h"
#include "D:/VS STUDIO C++/GameSLD/GameSLD/BaseObject.h"

BaseObject g_background;


bool InitData()
{
	bool success = true;
	int ret = SDL_Init(SDL_INIT_VIDEO);
	if (ret < 0)
		return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("Game Cpp SDL 2.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (g_window == NULL)
	{
		success = false;
	}
	else
	{
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL) success = false;
		else
		{
			SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 1);
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) && imgFlags))
				success = false;
		}
	}

	return success;






}
bool loadBackground()
{
	bool ret = g_background.LoadImg("IMG/background.png", g_screen);
	if (ret == false) return false;


	return true;
}
void close()
{
	g_background.Free();
	SDL_DestroyRenderer(g_screen);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();

}

int main(int argc, char* argv[])
{
	if (InitData() == false) return -1;
	if (loadBackground() == false) return -1;
	bool is_quit = false;
	while (!is_quit)
	{
		while (SDL_PollEvent(&g_event) != 0)

		{
			if (g_event.type == SDL_QUIT)
			{
				is_quit = true;
			}

		}
		SDL_SetRenderDrawColor(g_screen, OLERENDER_DRAW, OLERENDER_DRAW, OLERENDER_DRAW, 1);
		SDL_RenderClear(g_screen);

		g_background.Render(g_screen, NULL);
		SDL_RenderPresent(g_screen);


	}


	return 0;
}


