#include "TestPasteAllTogether.h"
#include "UnitedRectangles.h"

#ifndef EASY
TestPasteAllTogether::TestPasteAllTogether(void)
{
}

void TestPasteAllTogether::ifNoContact (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector <Rectangle> vect;	// ������� ������
	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -2, 2, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (1, -1, 2, 3);	// ������ ��������� ��� ������� ��������������

	vect << first << second;

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1 << QPoint::QPoint(-3, -2) << QPoint::QPoint(-3, 2) << QPoint::QPoint(-1, 2) << QPoint::QPoint(-1, -2);
	intersections2 << QPoint::QPoint(1, -1) << QPoint::QPoint(1, 2) << QPoint::QPoint(3, 2) << QPoint::QPoint(3, -1);
	data << intersections1 << intersections2;

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� �� ������������� - ���� �� �������!");
}

void TestPasteAllTogether::ifIsContact (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector <Rectangle> vect;	// ������� ������
	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-2, 1, 3, 2);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 3, 2);	// ������ ��������� ��� ������� ��������������

	vect << first << second;

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1;	// ����� �����������

	intersections1 << QPoint::QPoint(-2, 3) << QPoint::QPoint(1, 3) << QPoint::QPoint(1, 1) << QPoint::QPoint(2, 1) << QPoint::QPoint(2, -1) << QPoint::QPoint(-1, -1) << QPoint::QPoint(-1, 1) << QPoint::QPoint(-2, 1);
	data << intersections1;

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� ������������� - ���� �� �������!");
}

void TestPasteAllTogether::ifIsIntersection (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector <Rectangle> vect;	// ������� ������
	Rectangle first;	// ������ �������������
	Rectangle second;	// ������ �������������

	first = Rectangle (-3, -2, 4, 3);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-1, -1, 3, 3);	// ������ ��������� ��� ������� ��������������

	vect << first << second;

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1;	// ����� �����������

	intersections1 << QPoint::QPoint(-3, 1) << QPoint::QPoint(-1, 1) << QPoint::QPoint(-1, 2) << QPoint::QPoint(2, 2) << QPoint::QPoint(2, -1) << QPoint::QPoint(1, -1) << QPoint::QPoint(1, -2) << QPoint::QPoint(-3, -2);
	data << intersections1;

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� ������������ - ���� �� �������!");
}

void TestPasteAllTogether::ifTwoHavesIntersectionsAndThirdHaveNot (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector <Rectangle> vect;	// ������� ������
	Rectangle first, second, third;	// ��������������

	first = Rectangle (-4, -3, 3, 2);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-2, -2, 2, 4);	// ������ ��������� ��� ������� ��������������
	third = Rectangle (1, 0, 3, 2);		// ������ ��������� ��� �������� ��������������

	vect << first << second << third;

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1 << QPoint::QPoint(-4, -1) << QPoint::QPoint(-2, -1) << QPoint::QPoint(-2, 2) << QPoint::QPoint(0, 2) << QPoint::QPoint(0, -2) << QPoint::QPoint(-1, -2) << QPoint::QPoint(-1, -3) << QPoint::QPoint(-4, -3);
	intersections2 << QPoint::QPoint(1, 2) << QPoint::QPoint(4, 2) << QPoint::QPoint(4, 0) << QPoint::QPoint(1, 0);
	data << intersections1 << intersections2;

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� ������������, � ������ �� ������������� �� � ����� �� ��� - ���� �� �������!");
}

void TestPasteAllTogether::ifSevenRectangles (void)
{
	UnitedRectangles app;	// ������� ������ � ������� ������������ ������

	QVector <Rectangle> vect;	// ������� ������
	Rectangle first, second, third, fourth, fifth, sixth, seventh;	// ��������������

	first = Rectangle (-4, 3, 1, 4);	// ������ ��������� ��� ������� ��������������
	second = Rectangle (-6, -1, 4, 4);	// ������ ��������� ��� ������� ��������������
	third = Rectangle (-6, -1, 2, 2);	// ������ ��������� ��� �������� ��������������
	fourth = Rectangle (-3, -3, 4, 3);	// ������ ��������� ��� ��������� ��������������
	fifth = Rectangle (-1, -7, 1, 5);	// ������ ��������� ��� ������ ��������������
	sixth = Rectangle (-3, -6, 5, 2);	// ������ ��������� ��� ������� ��������������
	seventh = Rectangle (0, 2, 2, 4);	// ������ ��������� ��� �������� ��������������

	vect << first << second << third << fourth << fifth << sixth << seventh;

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1 << QPoint::QPoint(-6, 3) << QPoint::QPoint(-4, 3) << QPoint::QPoint(-4, 7) << QPoint::QPoint(-3, 7) << QPoint::QPoint(-3, 3) << QPoint::QPoint(-2, 3) << QPoint::QPoint(-2, 0) << QPoint::QPoint(1, 0) << QPoint::QPoint(1, -3) << QPoint::QPoint(0, -3) << QPoint::QPoint(0, -4) << QPoint::QPoint(-2, -4) << QPoint::QPoint(-2, -6) << QPoint::QPoint(0, -6) << QPoint::QPoint(0, -7) << QPoint::QPoint(-1, -7) << QPoint::QPoint(-1, -6) << QPoint::QPoint(-3, -6) << QPoint::QPoint(-3, -4) << QPoint::QPoint(-1, -4) << QPoint::QPoint(-1, -3) << QPoint::QPoint(-3, -3) << QPoint::QPoint(-3, -1) << QPoint::QPoint(-6, -1);
	intersections2 << QPoint::QPoint(0, 6) << QPoint::QPoint(2, 6) << QPoint::QPoint(2, 2) << QPoint::QPoint(0, 2);
	data << intersections1 << intersections2;

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� ������������, � ������ �� ������������� �� � ����� �� ��� - ���� �� �������!");
}

TestPasteAllTogether::~TestPasteAllTogether(void)
{
}
#endif