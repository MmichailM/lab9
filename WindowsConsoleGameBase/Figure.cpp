#include "Figure.h"

void Figure::update(double dt) {
	m_TimeFromLastUpdatec += dt;
	if (m_TimeFromLastUpdatec > m_TimeForUpdate) {
		m_TimeFromLastUpdatec = 0;
		++m_Position.y;
	}
}

void Figure::render(PaintDevice& paintDevice) {
	for (const Point& point : m_Body[m_CurrentRotate]) {
		Vector2 v(point.x + m_Position.x,
			point.y + m_Position.y);
		paintDevice.set_char(v, 0x25D8);
	}
}

void Figure::move_right() {
	m_Position.x++;
}

void Figure::move_left() {
	m_Position.x--;
}

const vector<Point>& Figure::get_body() const {
	return m_Body[m_CurrentRotate];
}

Point Figure::get_position() const {
	return m_Position;
}

void Figure::set_position(Point position) {
	m_Position = position;
}

void Figure::backup() {
	m_PositionBackup = m_Position;
	m_CurrentRotateBackup = m_CurrentRotate;
}

void Figure::restore() {
	m_Position = m_PositionBackup;
	m_CurrentRotate = m_CurrentRotateBackup;
}

void Figure::boost() {
	m_TimeForUpdate = 50;
}

void Figure::rotate() {
	if (m_CurrentRotate < 3) m_CurrentRotate++;
	else m_CurrentRotate = 0;
}
