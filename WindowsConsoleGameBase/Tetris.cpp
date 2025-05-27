#include "Tetris.h"

Tetris::Tetris() {
	paint_device().resize(Size(m_Width + 6, m_Height));
	m_GameField.resize(m_Width, m_Height);
	m_Figure = new IBlock(Point(5, 1));
	track_key(VK_LEFT);
	track_key(VK_RIGHT);
}

void Tetris::render(PaintDevice& paintDevice) {
	m_GameField.render(paintDevice);
	m_Figure->render(paintDevice);
}

void Tetris::update(const int dt) {
	m_Figure->update(dt);
	if (m_GameField.has_collision(*m_Figure)) {
		m_Figure = new IBlock(Point(5, 1));
	}
}

void Tetris::on_button_press(const int button) {
	switch (button) {
	case VK_LEFT:
		m_Figure->move_left();
		break;
	case VK_RIGHT:
		m_Figure->move_right();
		break;
	}

}
