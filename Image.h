#pragma once

#include "Canvas.h"
#include <string>

class Image
{
public:
	Image() {}
	~Image() {}

	bool Load(const std::string& filename, Uint8 alpha = 255);

	friend class Canvas;
protected:
	std::vector<pixel_t> m_buffer;

	int m_width{ 0 };
	int m_height{ 0 };
};