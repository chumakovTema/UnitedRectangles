//!
//! \file Intersection.h
//!
#pragma once
#include <QList>
#include <QPoint>

/*!
* \class Intersection
* Класс, определяющий вид пересечения прямоугольников
*/
class Intersection
{
public:
	Intersection(void);
	Intersection (int, int, bool, QList <QPoint>);
	~Intersection(void);

	int baseIndex;	/**< int baseIndex - Индекс первого прямоугольника */
	int secondIndex;/**< int secondIndex - Индекс второго прямоугольника */
	bool sign;		/**< bool sign - Признак пересечения или соприкосновения прямоугольников */
	QList <QPoint> intersection;/**< QList <QPoint> intersection - Список точек, в которых прямоугольники пересекаются */

	//!
	//! Перегруженная операция сравнения пересечений
	//!
	bool operator == (const Intersection &);
};