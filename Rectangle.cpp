//!
//! \file Rectangle.cpp
//!
#include "Rectangle.h"

/*!
* \fn Rectangle::Rectangle(void)
* ����������� �� ���������
*/
Rectangle::Rectangle(void)
{
}

/*!
* \fn Rectangle::Rectangle (int X, int Y, int L, int W)
* ����������� � �����������
* \param [in] X - ����������-�������� ������� �����
* \param [in] Y - ����������-�������� ������� �����
* \param [in] L - ����� ��������������
* \param [in] W - ������ ��������������
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
* ���������� �� ���������
*/
Rectangle::~Rectangle(void)
{
}
