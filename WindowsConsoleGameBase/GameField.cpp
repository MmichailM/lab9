#include "GameField.h"

void GameField::resize(size_t width, size_t height) {
	m_Width = width;
	m_Height = height;
}

void GameField::render(PaintDevice& paintDevice) {
	Vector2 v1(0, 0);
	paintDevice.set_char(v1, 0x2550);
}
