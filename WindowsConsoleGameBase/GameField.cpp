#include "GameField.h"

void GameField::resize(size_t width, size_t height) {
	m_Width = width;
	m_Height = height;
	m_Field = vector<vector<wchar_t>>(m_Height - 2, vector<wchar_t>(m_Width - 2, 0x0387));
}

void GameField::render(PaintDevice& paintDevice) {
	for (int i = 1; i < m_Width - 1; i++) {
		Vector2 v1(i, 0);
		paintDevice.set_char(v1, 0x2550);
	}

	for (int i = 1; i < m_Height - 1; i++) {
		Vector2 v2(m_Width - 1, i);
		paintDevice.set_char(v2, 0x2551);
	}

	for (int i = 1; i < m_Height - 1; i++) {
		Vector2 v3(0, i);
		paintDevice.set_char(v3, 0x2551);
	}

	for (int i = 1; i < m_Width - 1; i++) {
		Vector2 v4(i, m_Height - 1);
		paintDevice.set_char(v4, 0x2550);
	}
	Vector2 v11(0, 0);
	paintDevice.set_char(v11, 0x2554);
	Vector2 v12(m_Width - 1, 0);
	paintDevice.set_char(v12, 0x2557);
	Vector2 v13(0, m_Height - 1);
	paintDevice.set_char(v13, 0x255A);
	Vector2 v14(m_Width - 1, m_Height - 1);
	paintDevice.set_char(v14, 0x255D);

	for (int y = 0; y < m_Field.size(); y++) {
		for (int x = 0; x < m_Field[y].size(); x++) {
			Vector2 v(x + 1, y + 1);
			paintDevice.set_char(v, m_Field[y][x]);
		}
	}
}

bool GameField::has_collision(const Figure& figure) {
	Point position = figure.get_position();
	for (const Point& point : figure.get_body()) {
		if (point.x + position.x < 1 || point.x + position.x > m_Width - 2) return true;
		if (point.y + position.y < 1 || point.y + position.y > m_Height - 2) return true;
	}
	return false;
}
