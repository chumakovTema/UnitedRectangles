//!
//! \file Rectangle.h
//!
#pragma once
#include <QTextStream>

/*!
* \class Rectangle
* �����, ����������� �������������
*/
class Rectangle
{
public:
	Rectangle(void);
	Rectangle (int, int, int, int);
	~Rectangle(void);

	int x;		/**< int x - ����������-�������� ������� ����� */
	int y;		/**< int y - ����������-�������� ������� ����� */
	int length;	/**< int length - ����� �������������� */
	int width;	/**< int width - ������ �������������� */
};