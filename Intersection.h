//!
//! \file Intersection.h
//!
#pragma once
#include <QPoint>

/*!
* \class Intersection
* �����, ������������ ��� ����������� ���������������
*/
class Intersection
{
public:
	Intersection(void);
	Intersection (int, int, bool);
	~Intersection(void);

	int baseIndex;	/**< int baseIndex - ������ ������� �������������� */
	int secondIndex;/**< int secondIndex - ������ ������� �������������� */
	bool sign;		/**< bool sign - ������� ����������� ��� ��������������� ��������������� */

	//!
	//! ������������� �������� ��������� �����������
	//!
	bool operator == (const Intersection &);
};