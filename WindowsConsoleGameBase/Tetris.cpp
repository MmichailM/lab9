#include "Tetris.h"

Tetris::Tetris() {
	paint_device().resize(Size(m_Width + 6, m_Height));
	m_GameField.resize(m_Width, m_Height);
}

void Tetris::render(PaintDevice& paintDevice) {
	m_GameField.render(paintDevice);
}
