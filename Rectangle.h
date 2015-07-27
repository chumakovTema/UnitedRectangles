//!
//! \file Rectangle.h
//!
#pragma once
#include <QTextStream>

/*!
* \class Rectangle
* Класс, описывающий прямоугольник
*/
class Rectangle
{
public:
	Rectangle(void);
	Rectangle (int, int, int, int);
	~Rectangle(void);

	int x;		/**< int x - Координата-абсцисса базовой точки */
	int y;		/**< int y - Координата-ордината базовой точки */
	int length;	/**< int length - Длина прямоугольника */
	int width;	/**< int width - Ширина прямоугольника */
};