#include "TestHasIntersectionWithAnother.h"
#include "UnitedRectangles.h"

#ifndef SPLICE_RECTANGLES_EASY_VERSION
TestHasIntersectionWithAnother::TestHasIntersectionWithAnother(void)
{
}

void TestHasIntersectionWithAnother::ifNoContactAndOneOutOfOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -2, 2, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (1, -1, 2, 3);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;// ����������� ������ �����
	list.clear();	// ���������� ������

	map = Intersection(0, 1, false, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �� �������������, ���� ��������� ������� ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifNoContactAndOneInOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, -2, 4, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 2, 2);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;// ����������� ������ �����
	list.clear();	// ���������� ������

	map = Intersection(0, 1, false, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �� �������������, ���� ��������� ������ ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifContactOneTop (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, 0, 3, 1);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (0, -2, 1, 2);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(0, 0);	// �������� ����� �������� � ������

	map = Intersection(0, 1, false, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, �� � ��� ����� ������ ���� ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifContactOneEdge (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, 1, 3, 2);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 3, 2);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, 1);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, ����� ��� ����� ������� ������ �������������� �������� ����� ��� ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifCrossOneEdge (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, -2, 3, 5);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 4, 3);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(1, -1) << QPoint::QPoint(1, 2);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� ������������, ���� �� ������ ������ �������������� ��������� ������ �� ��� ����� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifCrossTwoAdjacentEdges (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -2, 4, 3);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 3, 3);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, -1);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� ������������, ���� ������������� ���������� ��� ������� ������� ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifCrossAnotherThrough (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -1, 5, 2);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-2, -2, 2, 4);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-2, 1) << QPoint::QPoint(0, 1) << QPoint::QPoint(0, -1) << QPoint::QPoint(-2, -1);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� ������������, ���� ������������� ���������� ��� ������� ������� � ��������� ��� �� ��� ����� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifContactAndOneInOtherAndOneDimensionLess (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, -3, 3, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-2, -3, 3, 2);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-2, -1) << QPoint::QPoint(1, -1) << QPoint::QPoint(1, -3) << QPoint::QPoint(-2, -3);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, ���� ������������� ��������� ������ �������, ���� ��������� ����� ��������������� ���������, � ������ ��������� � ������ �� ��������������� ������, ��� � ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifContactAndOneInOtherAndBothDimensionsLess (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, -1, 5, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (0, 0, 3, 3);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(0, 3) << QPoint::QPoint(3, 3) << QPoint::QPoint(3, 0);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, ���� ������������� ��������� ������ �������, �� � ������ �������������� ��� ��������� ������, ��� � ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifContactTwoOppositeEdgesAndOneInOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -2, 5, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -2, 2, 4);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-1, 2) << QPoint::QPoint(1, 2) << QPoint::QPoint(1, -2) << QPoint::QPoint(-1, -2);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, ���� ��������� ������ �������, ��������������� ������� ������ �������������� �������� ������ ��� ��������������� ������ ������� - ���� �� �������!");
}

void TestHasIntersectionWithAnother::ifConcurWitnOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, -1, 3, 3);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-2, -1, 3, 3);	// ������ ��������� ��� ������� ��������������

	QVector<QVector<Intersection>> data;// ��������� ������
	QVector<Intersection> intersections;// ����� �����������
	Intersection map;

	QList <QPoint> list;	// ����������� ������ �����
	list.clear();			// ���������� ������
	list << QPoint::QPoint(-2, -1) << QPoint::QPoint(-2, 2) << QPoint::QPoint(1, 2) << QPoint::QPoint(1, -1);	// �������� ����� �������� � ������

	map = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections.append(map);
	data.append(intersections);	// �������� � � ��������� ������

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "�������������� �������������, ���� ��������� ������ �������, ��������������� ������� ������ �������������� �������� ������ ��� ��������������� ������ ������� - ���� �� �������!");
}

TestHasIntersectionWithAnother::~TestHasIntersectionWithAnother(void)
{
}
#endif