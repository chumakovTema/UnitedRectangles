#include "TestPasteTogether.h"
#include "UnitedRectangles.h"
#include <QVector>
#include <QPoint>
#include <QList>

#ifndef SPLICE_RECTANGLES_EASY_VERSION
TestPasteTogether::TestPasteTogether(void)
{
}

void TestPasteTogether::ifContactOneEdge (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-3, 2) << QPoint::QPoint(-1, 2) << QPoint::QPoint(-1, 1) << QPoint::QPoint(2, 1) << QPoint::QPoint(2, -1) << QPoint::QPoint(-1, -1) << QPoint::QPoint(-1, -2) << QPoint::QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(-1, -1);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(-1, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "�������������� ������������� ����� �������� - ���� �� �������!");
}

void TestPasteTogether::ifCrossOneEdge (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-1, 2) << QPoint::QPoint(0, 2) << QPoint::QPoint(0, -1) << QPoint::QPoint(1, -1) << QPoint::QPoint(1, -3) << QPoint::QPoint(-2, -3) << QPoint::QPoint(-2, -1) << QPoint::QPoint(-1, -1);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-1, -1) << QPoint::QPoint(0, -1);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-1, -1) << QPoint::QPoint(0, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "���� ������������� ���������� ������� �������, � ������� ����� ��� ����� ����� - ���� �� �������!");
}

void TestPasteTogether::ifCrossCorner (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-3, 1) << QPoint::QPoint(-1, 1) << QPoint::QPoint(-1, 2) << QPoint::QPoint(3, 2) << QPoint::QPoint(3, -1) << QPoint::QPoint(1, -1) << QPoint::QPoint(1, -2) << QPoint::QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, -1);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "���� ������������� ���������� ���� ������� � ����� � ��� ����� �������� ��������� �� ����� ����� ����� - ���� �� �������!");
}

void TestPasteTogether::ifCrossTwoOppositeEdges (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-3, 2) << QPoint::QPoint(-2, 2) << QPoint::QPoint(-2, 3) << QPoint::QPoint(2, 3) << QPoint::QPoint(2, 2) << QPoint::QPoint(3, 2) << QPoint::QPoint(3, -2) << QPoint::QPoint(2, -2) << QPoint::QPoint(2, -3) << QPoint::QPoint(-2, -3) << QPoint::QPoint(-2, -2) << QPoint::QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -2) << QPoint::QPoint(-2, -2);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -2) << QPoint::QPoint(-2, -2);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "���� ������������� ���������� ��� ��������������� ������� ������� � ����� � ��� ������ ����� ����� - ���� �� �������!");
}

void TestPasteTogether::ifContactOneInOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-2, 2) << QPoint::QPoint(1, 2) << QPoint::QPoint(1, -3) << QPoint::QPoint(-2, -3);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(0, 2) << QPoint::QPoint(2, -1);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(0, 2) << QPoint::QPoint(2, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "�������������� �������������, ���� ������������� ��������� ������ ������� - ���� �� �������!");
}

void TestPasteTogether::ifConcurWitnOther (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector<QVector<QPoint>> points;	// ��������� ������
	QVector<QPoint> map;	// ��������� �����������
	map << QPoint::QPoint(-2, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -1) << QPoint::QPoint(-2, -1);
	points.append(map);

	QVector<QVector<Intersection>> data;	// ������� ������
	QVector<Intersection> intersections1, intersections2;// ����� �����������
	Intersection map1, map2;

	QList <QPoint> list;// ����������� ������ �����

	list.clear();		// ���������� ������
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -1) << QPoint::QPoint(-2, -1);
	map1 = Intersection(0, 1, true, list);	// ����������� ����� �����������
	intersections1.append(map1);

	list.clear();
	list << QPoint::QPoint(-2, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -1) << QPoint::QPoint(-2, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data.append(intersections1);	// �������� � � ��������� ������
	data.append(intersections2);

	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "�������������� ��������� - ���� �� �������!");
}

TestPasteTogether::~TestPasteTogether(void)
{
}
#endif