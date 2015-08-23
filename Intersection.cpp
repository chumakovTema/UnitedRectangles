//!
//! \file Intersection.cpp
//!
#include "Intersection.h"

/*!
* \fn Intersection::Intersection(void)
*  онструктор по умолчанию
*/
Intersection::Intersection(void)
{
}

/*!
* \fn bool Intersection::operator == (const Intersection & other)
* ѕерегруженна€ операци€ сравнени€ пересечений
* \param [in] other - пересечение, правый операнд
* \return признак равенства пересечений
*/
bool Intersection::operator == (const Intersection & other)
{
	return baseIndex == other.baseIndex && secondIndex == other.secondIndex && sign == other.sign;
}

/*!
* \fn Intersection::Intersection (int I1, int I2, bool S, QList <QPoint> INT)
*  онструктор с параметрами
* \param [in] I1 - индекс первого пр€моугольника
* \param [in] I2 - индекс второго пр€моугольника
* \param [in] S - признак пересечени€ или соприкосновени€ пр€моугольников
* \param [in] INT - список точек, в которых пр€моугольники пересекаютс€
*/
Intersection::Intersection (int I1, int I2, bool S)
{
	Intersection::baseIndex = I1;
	Intersection::secondIndex = I2;
	Intersection::sign = S;
}

/*!
* \fn Intersection::Intersection(void)
* ƒеструктор по умолчанию
*/
Intersection::~Intersection(void)
{
}
