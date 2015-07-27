//!
//! \file Intersection.h
//!
#pragma once
#include <QList>
#include <QPoint>

/*!
* \class Intersection
* �����, ������������ ��� ����������� ���������������
*/
class Intersection
{
public:
	Intersection(void);
	Intersection (int, int, bool, QList <QPoint>);
	~Intersection(void);

	int baseIndex;	/**< int baseIndex - ������ ������� �������������� */
	int secondIndex;/**< int secondIndex - ������ ������� �������������� */
	bool sign;		/**< bool sign - ������� ����������� ��� ��������������� ��������������� */
	QList <QPoint> intersection;/**< QList <QPoint> intersection - ������ �����, � ������� �������������� ������������ */

	//!
	//! ������������� �������� ��������� �����������
	//!
	bool operator == (const Intersection &);
};