#pragma once
#include <QList>
#include <QPoint>

class Intersection
{
public:
	Intersection(void);
	Intersection (int, int, bool, QList <QPoint>);
	~Intersection(void);

	int baseIndex;
	int secondIndex;
	bool sign;
	QList <QPoint> intersection;

	bool operator == (const Intersection &);
};