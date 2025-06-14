#pragma once
#include "Engine.h"
#include <vector>
#include "IBlock.h"

using namespace std;

class GameField {
	size_t m_Width;
	size_t m_Height;
	vector<vector<wchar_t>> m_Field;
public:
	void resize(size_t width, size_t height);
	void render(PaintDevice& paintDevice);
	bool has_collision(const Figure& figure);
	void merge(const Figure& figure);
};

