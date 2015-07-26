#pragma once
#include <QVector>
#include <QList>
#include <QPoint>
#include <QTextStream>
#include <QFile>
#include "Rectangle.h"
#include "Intersection.h"

class UnitedRectangles
{
public:
	UnitedRectangles(void);
	~UnitedRectangles(void);

	QVector <Rectangle> readData ();		// ������ ������ �� �����
	QVector<QPoint> getTops (Rectangle it);	// ��������� ��������� ���� ������ ��������������

#ifdef EASY	// ���������� ������ �������
	Rectangle pasteAllTogetherEasy (QVector<Rectangle> & rectangles);	// ������� ��������������� � ����
	void writeResultEasy (Rectangle & figure);							// ������ ������ � ����
#else		// ���������� �������� �������, ������ ������� ��� ��������� ������
	QVector<QVector<QPoint>> pasteAllTogether (QVector<Rectangle> & rectangles);
	QVector<QVector<Intersection>> hasIntersectionWithAhother (Rectangle first, int num1, Rectangle other, int num2);
	QVector<QVector<QPoint>> pasteTogether (QVector<QVector<Intersection>> & intersections, const int count);
	void writeResult (QVector<QVector<QPoint>> & figures);			// ������ ������ � ����
#endif
};

QTextStream & operator >> (QTextStream & in, Rectangle & other);
QTextStream & operator << (QTextStream & out, const QPoint & other);