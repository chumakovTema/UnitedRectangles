//!
//! \file Intersection.cpp
//!
#include "Intersection.h"

/*!
* \fn Intersection::Intersection(void)
* ����������� �� ���������
*/
Intersection::Intersection(void)
{
}

/*!
* \fn bool Intersection::operator == (const Intersection & other)
* ������������� �������� ��������� �����������
* \param [in] other - �����������, ������ �������
* \return ������� ��������� �����������
*/
bool Intersection::operator == (const Intersection & other)
{
	return baseIndex == other.baseIndex && secondIndex == other.secondIndex && sign == other.sign;
}

/*!
* \fn Intersection::Intersection (int I1, int I2, bool S, QList <QPoint> INT)
* ����������� � �����������
* \param [in] I1 - ������ ������� ��������������
* \param [in] I2 - ������ ������� ��������������
* \param [in] S - ������� ����������� ��� ��������������� ���������������
* \param [in] INT - ������ �����, � ������� �������������� ������������
*/
Intersection::Intersection (int I1, int I2, bool S)
{
	Intersection::baseIndex = I1;
	Intersection::secondIndex = I2;
	Intersection::sign = S;
}

/*!
* \fn Intersection::Intersection(void)
* ���������� �� ���������
*/
Intersection::~Intersection(void)
{
}
