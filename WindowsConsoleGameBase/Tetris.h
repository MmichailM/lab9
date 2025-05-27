#pragma once

#include "Engine.h"
#include "GameField.h"
#include "IBlock.h"

class Tetris : public Engine {
	const size_t m_Width = 14;
	const size_t m_Height = 26;
	GameField m_GameField;
	Figure* m_Figure;
public:
	Tetris();
	bool end() const { return false; }
	void on_button_press(const int button);
	void update(const int dt);
	void render(PaintDevice& paintDevice);
	virtual ~Tetris() {}
};

