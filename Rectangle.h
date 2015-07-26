#pragma once
#include <QTextStream>

class Rectangle
{
public:
	Rectangle(void);
	Rectangle (int, int, int, int);
	~Rectangle(void);

	int x;
	int y;
	int length;
	int width;
};