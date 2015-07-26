#include "Intersection.h"

Intersection::Intersection(void)
{
}

bool Intersection::operator == (const Intersection & other)
{
	return baseIndex == other.baseIndex && secondIndex == other.secondIndex && sign == other.sign && intersection == other.intersection;
}

Intersection::Intersection (int I1, int I2, bool S, QList <QPoint> INT)
{
	Intersection::baseIndex = I1;
	Intersection::secondIndex = I2;
	Intersection::sign = S;
	Intersection::intersection = INT;
}

Intersection::~Intersection(void)
{
}
