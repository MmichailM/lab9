#pragma once

#include "Engine.h"

class Tetris : public Engine {
	bool end() const {} 
	void on_button_press(const int button) {}
	void update(const int dt) {}
	void render(PaintDevice& paintDevice) {}
};

