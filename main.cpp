
#include "Canvas.h"
#include "Image.h"
#include "SDL.h"
#include <iostream>

int main(int, char**)
{
	const int width = 800;
	const int height = 600;
	//GitHub clone test

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("2D Renderer", 100, 100, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	Canvas canvas(renderer, width, height);
	Image image;
	image.Load("cat.bmp");

	Image image2;
	image2.Load("sus.bmp");

	Image image3;
	image3.Load("color.bmp", 128);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		canvas.Clear({ 0, 0, 0, 255 });
		/*
		//Draw Points
		for (int i = 0; i < 100; i++)
		{
			canvas.DrawPoint({ rand() % width, rand() % height }, 
				{ 255, 255, 255, 255 });
		}
		//Draw Line
		canvas.DrawLine({ rand() % width, rand() % height }, 
			{ rand() % width, rand() % height }, 
			{ (Uint8)(rand() % 255), (Uint8)(rand() % 255), (Uint8)(rand() % 255), 255 });
		//Draw Line List
		std::vector<SDL_Point> points;
		for (int i = 0; i < 10; i++)
		{
			points.push_back({ rand() % width, rand() % height });
		}
		canvas.DrawLineList(points, { (Uint8)(rand() % 255), (Uint8)(rand() % 255), (Uint8)(rand() % 255), 255 });
		//Draw Triangle
		canvas.DrawTriangle({ 10, 250 }, 
			{ 10, 400 }, 
			{ 200, 400 }, 
			{ 255, 255, 255, 255 });
		//Draw Rect
		canvas.DrawRect({ 10, 30, 300, 200 }, { 255, 255, 255, 255 });
		//Draw Circle
		canvas.DrawCircle({500, 400}, 100, { 255, 255, 255, 255 });
		*/
		canvas.DrawImage(&image, { 100, 100 });
		canvas.DrawImage(&image2, { 300, 300 }, { 0, 255, 0, 255 });
		canvas.DrawImage(&image3, { 400, 400 });

		//canvas.ProcessInvert();
		//canvas.ProcessMonochrome();
		//canvas.ProcessNightvision();
		//canvas.ProcessThreshold({180, 180, 180, 255});
		//canvas.ProcessBrightness(-100);
		//canvas.ProcessColor(50, 50, -100);

		canvas.Update();

		SDL_RenderClear(renderer);
		canvas.Draw(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return 0;
}
