#pragma once
#include "Engine.h"

class GameField {
	size_t m_Width;
	size_t m_Height;
public:
	void resize(size_t width, size_t height);
	void render(PaintDevice& paintDevice);
};

