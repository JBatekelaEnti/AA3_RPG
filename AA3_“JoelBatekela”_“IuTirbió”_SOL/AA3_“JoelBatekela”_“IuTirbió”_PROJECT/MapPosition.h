#pragma once
#include <stdlib.h>
struct MapPosition
{
	int x;
	int y;

	MapPosition(int x, int y): x(x), y(y) {};
	MapPosition() = default;
};