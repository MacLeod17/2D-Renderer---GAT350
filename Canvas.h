#pragma once

#include "SDL.h"
#include <vector>

using pixel_t = Uint32;
inline SDL_Color PixelToColor(const pixel_t& pixel);
inline pixel_t ColorToPixel(const SDL_Color& color);

class Canvas
{
public:
	Canvas(SDL_Renderer* renderer, int width, int height);
	~Canvas();

	void Update();
	void Draw(SDL_Renderer* renderer);
	void Clear(const SDL_Color& color);
	void DrawPoint(const SDL_Point& point, const SDL_Color& color);
	void DrawLine(const SDL_Point& v1, const SDL_Point& v2, const SDL_Color& color);
	void DrawLineList(const std::vector<SDL_Point>& points, const SDL_Color& color);
	void DrawTriangle(const SDL_Point& p1, const SDL_Point& p2, const SDL_Point& p3, const SDL_Color& color);
	void DrawRect(const SDL_Rect& rect, const SDL_Color& color);
	void DrawCircle(const SDL_Point& center, int radius, const SDL_Color& color);

	void DrawImage(const class Image* image, const SDL_Point& point);
	void DrawImage(const class Image* image, const SDL_Point& point, const SDL_Color& key);

	void ProcessInvert();
	void ProcessMonochrome();
	void ProcessNightvision();
	void ProcessThreshold(const SDL_Color& threshold);
	void ProcessBrightness(const int brightness);
	void ProcessColor(int r, int g, int b);

protected:
	void DrawCirclePoint(const SDL_Point& center, const SDL_Point& point, const SDL_Color& color);

private:
	SDL_Texture* m_texture{ nullptr };
	std::vector<pixel_t> m_buffer;
	int m_width;
	int m_height;
};