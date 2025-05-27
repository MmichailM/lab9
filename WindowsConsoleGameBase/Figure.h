#pragma once
#include <vector>
#include "Engine.h"

using namespace std;

struct Point {
	int x;
	int y;
	Point(int x = 0, int y = 0) : x(x), y(y) {}
};

class Figure {
protected:
	Point m_Position;
	double m_TimeFromLastUpdatec = 0;
	double m_TimeForUpdate = 500; //полсекунды
	vector<vector<Point>> m_Body;
	size_t m_CurrentRotate = 0;
	Point m_PositionBackup;
	size_t m_CurrentRotateBackup = 0;
public:
	Figure(Point position) : m_Position(position) {}
	void update(double dt);
	void render(PaintDevice& paintDevice);
	void move_right();
	void move_left();
	const vector<Point>& get_body() const;
	Point get_position() const;
	void set_position(Point position);
	void backup();
	void restore();
	void boost();
	void rotate();
};

