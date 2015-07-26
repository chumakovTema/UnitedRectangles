#include "Rectangle.h"

Rectangle::Rectangle(void)
{
}

Rectangle::Rectangle (int X, int Y, int L, int W)
{
	Rectangle::x = X;
	Rectangle::y = Y;
	Rectangle::length = L;
	Rectangle::width = W;
}

Rectangle::~Rectangle(void)
{
}
