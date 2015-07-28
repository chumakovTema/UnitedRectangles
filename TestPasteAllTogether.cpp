#include "TestPasteAllTogether.h"
#include "UnitedRectangles.h"

#ifndef SPLICE_RECTANGLES_EASY_VERSION
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

	vect.append(first);
	vect.append(second);

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1.append(QPoint(-3, -2)); 
	intersections1.append(QPoint(-3, 2));
	intersections1.append(QPoint(-1, 2));
	intersections1.append(QPoint(-1, -2));

	intersections2.append(QPoint(1, -1));
	intersections2.append(QPoint(1, 2));
	intersections2.append(QPoint(3, 2));
	intersections2.append(QPoint(3, -1));

	data.append(intersections1);
	data.append(intersections2);

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

	vect.append(first);
	vect.append(second);

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1;	// ����� �����������

	intersections1.append(QPoint(-2, 3));
	intersections1.append(QPoint(1, 3));
	intersections1.append(QPoint(1, 1));
	intersections1.append(QPoint(2, 1));
	intersections1.append(QPoint(2, -1));
	intersections1.append(QPoint(-1, -1));
	intersections1.append(QPoint(-1, 1));
	intersections1.append(QPoint(-2, 1));
	
	data.append(intersections1);

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

	vect.append(first);
	vect.append(second);

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1;	// ����� �����������

	intersections1.append(QPoint(-3, 1));
	intersections1.append(QPoint(-1, 1));
	intersections1.append(QPoint(-1, 2));
	intersections1.append(QPoint(2, 2));
	intersections1.append(QPoint(2, -1));
	intersections1.append(QPoint(1, -1));
	intersections1.append(QPoint(1, -2));
	intersections1.append(QPoint(-3, -2));
	
	data.append(intersections1);

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

	vect.append(first);
	vect.append(second);
	vect.append(third);

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1.append(QPoint(-4, -1));
	intersections1.append(QPoint(-2, -1));
	intersections1.append(QPoint(-2, 2));
	intersections1.append(QPoint(0, 2));
	intersections1.append(QPoint(0, -2));
	intersections1.append(QPoint(-1, -2));
	intersections1.append(QPoint(-1, -3));
	intersections1.append(QPoint(-4, -3));
	
	intersections2.append(QPoint(1, 2));
	intersections2.append(QPoint(4, 2));
	intersections2.append(QPoint(4, 0));
	intersections2.append(QPoint(1, 0));
	
	data.append(intersections1);
	data.append(intersections2);

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

	vect.append(first);
	vect.append(second);
	vect.append(third);
	vect.append(fourth);
	vect.append(fifth);
	vect.append(sixth);
	vect.append(seventh);

	QVector<QVector<QPoint>> data;	// ��������� ������
	QVector<QPoint> intersections1, intersections2;	// ����� �����������

	intersections1.append(QPoint(-6, 3));
	intersections1.append(QPoint(-4, 3));
	intersections1.append(QPoint(-4, 7));
	intersections1.append(QPoint(-3, 7));
	intersections1.append(QPoint(-3, 3));
	intersections1.append(QPoint(-2, 3));
	intersections1.append(QPoint(-2, 0));
	intersections1.append(QPoint(1, 0));
	intersections1.append(QPoint(1, -3));
	intersections1.append(QPoint(0, -3));
	intersections1.append(QPoint(0, -4));
	intersections1.append(QPoint(-2, -4));
	intersections1.append(QPoint(-2, -6));
	intersections1.append(QPoint(0, -6));
	intersections1.append(QPoint(0, -7));
	intersections1.append(QPoint(-1, -7));
	intersections1.append(QPoint(-1, -6));
	intersections1.append(QPoint(-3, -6));
	intersections1.append(QPoint(-3, -4));
	intersections1.append(QPoint(-1, -4));
	intersections1.append(QPoint(-1, -3));
	intersections1.append(QPoint(-3, -3));
	intersections1.append(QPoint(-3, -1));
	intersections1.append(QPoint(-6, -1));

	intersections2.append(QPoint(0, 6));
	intersections2.append(QPoint(2, 6));
	intersections2.append(QPoint(2, 2));
	intersections2.append(QPoint(0, 2));
	
	data.append(intersections1);
	data.append(intersections2);

	QVERIFY2(app.pasteAllTogether(vect) == data, "��� �������������� ������������, � ������ �� ������������� �� � ����� �� ��� - ���� �� �������!");
}

TestPasteAllTogether::~TestPasteAllTogether(void)
{
}
#endif