//!
//! \file UnitedRectangles.h
//!
#pragma once
#include <QVector>
#include <QList>
#include <QPoint>
#include <QTextStream>
#include <QFile>
#include "Rectangle.h"
#include "Intersection.h"

/*!
* \class UnitedRectangles
* ������� �����
*/
class UnitedRectangles
{
public:
	UnitedRectangles(void);
	~UnitedRectangles(void);

	//!
	//! ������ ������ �� �����
	//!
	QVector <Rectangle> readData ();

	//!
	//! ��������� ��������� ���� ������ ��������������
	//!
	QVector<QPoint> getTops (Rectangle it);

	//!
	//! �������� ��������� ������� ������
	//!
	int correctInput (QVector <Rectangle> & rectangles);

	//!
	//! �������� ��������� �������� ������
	//!
	int correctOutput (QVector<Rectangle> & figure);

	//!
	//!	����������� ����� �����������
	//!
	QVector<QVector<int>> hasIntersectionWithAhother (QVector <Rectangle> & rectangles);

	//!
	//! ������� ��������������� � �����
	//!
	QVector<Rectangle> pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap);

	//!
	//! ���������� �����, ���� � � ��������� ���� ������������� ��������
	//!
	void rebuildMap (QVector<QVector<int>> & map);

	//!
	//! ������ ���������� ��������������� � ����
	//!
	void writeResult (QVector<Rectangle>  & newFigures);
};

//!
//! ������������� �������� ������ �� ���������� ������
//!
QTextStream & operator >> (QTextStream & in, Rectangle & other);

//!
//! ������������� �������� ������ � ��������� �����
//!
QTextStream & operator << (QTextStream & out, const QPoint & other);