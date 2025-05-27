#include "IBlock.h"

IBlock::IBlock(Point position) : Figure(position) {
	m_Body = { Point(1,0), Point(1,1),
	Point(1,2), Point(1,3) };
}
