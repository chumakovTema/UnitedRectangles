#include "testPasteTogether.h"
#include "UnitedRectangles.h"

testPasteTogether::testPasteTogether(void)
{
}

void testPasteTogether::secondInLeftDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, -2, 3, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, -2, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � �����-������ ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInLeftUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, 2, 3, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, 0, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � �����-������� ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInRightDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, -2, 3, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, -2, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ������-������ ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInRightUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, 2, 3, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ������-������� ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInLeftSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 4, 4) << Rectangle(-2, 1, 3, 2);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, 0, 6, 4);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ����� ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 4, 4) << Rectangle(1, 3, 2, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 4, 6);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ������� ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInRightSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 4, 4) << Rectangle(3, 1, 3, 2);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 6, 4);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ������ ������� � ������ ��������������� - ���� ��������!");
}

void testPasteTogether::secondInDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// ������� ������ ���������������
	input << Rectangle(0, 0, 4, 4) << Rectangle(1, -2, 2, 3);

	QVector<QVector<int>> map;	// ������� ����� �����������
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, -2, 4, 6);

	QVERIFY2(test.pasteTogether(input, map) == output, "������� �������������� � ������ ������� � ������ ��������������� - ���� ��������!");
}

testPasteTogether::~testPasteTogether(void)
{
}
