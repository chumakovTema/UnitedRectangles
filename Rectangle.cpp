//!
//! \file Rectangle.cpp
//!
#include "Rectangle.h"

/*!
* \fn Rectangle::Rectangle(void)
* Конструктор по умолчанию
*/
Rectangle::Rectangle(void)
{
}

/*!
* \fn Rectangle::Rectangle (int X, int Y, int L, int W)
* Конструктор с параметрами
* \param [in] X - Координата-абсцисса базовой точки
* \param [in] Y - Координата-ордината базовой точки
* \param [in] L - Длина прямоугольника
* \param [in] W - Ширина прямоугольника
*/
Rectangle::Rectangle (int X, int Y, int L, int W)
{
	Rectangle::x = X;
	Rectangle::y = Y;
	Rectangle::length = L;
	Rectangle::width = W;
}

/*!
* \fn Rectangle::~Rectangle(void)
* Деструктор по умолчанию
*/
Rectangle::~Rectangle(void)
{
}
