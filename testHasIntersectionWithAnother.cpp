#include "testHasIntersectionWithAnother.h"
#include "UnitedRectangles.h"

testHasIntersectionWithAnother::testHasIntersectionWithAnother(void)
{
}

void testHasIntersectionWithAnother::inSectorIAndContact ()
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, 2, 3, 3);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line;
	line << 0 << 1;	// ��������� ���������
	output << line;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� ������������ � ������� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inSectorIAndNoContact ()
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(4, 2, 3, 3);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line1, line2;
	line1 << 0;	// ��������� ������ ���������
	line2 << 1;	// ��������� ������ ���������
	output << line1 << line2;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� �� ������������ � ������� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inLeftSectorAndContact ()		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(-3, 1, 4, 2);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line;
	line << 0 << 1;	// ��������� ���������
	output << line;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� �� ������������ � ������� ����� �� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inLeftSectorAndNoContact ()	// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(-4, 2, 3, 2);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line1, line2;
	line1 << 0;	// ��������� ������ ���������
	line2 << 1;	// ��������� ������ ���������
	output << line1 << line2;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� �� ������������ � ������� ����� �� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inDownSectorAndContact ()		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(1, -2, 1, 3);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line;
	line << 0 << 1;	// ��������� ���������
	output << line;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� ������������ � ������� ����� �� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inDownSectorAndNoContact ()	// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, -3, 3, 2);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line1, line2;
	line1 << 0;	// ��������� ������ ���������
	line2 << 1;	// ��������� ������ ���������
	output << line1 << line2;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� �� ������������ � ������� c���� �� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inLeftDownSectorAndContact ()		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, -2, 3, 3);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line;
	line << 0 << 1;	// ��������� ���������
	output << line;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� ������������ � ������� �����-����� �� �������� �������������� - ���� ��������!");
}

void testHasIntersectionWithAnother::inLeftDownSectorAndNoContact ()	// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
{
	UnitedRectangles test;	// ������� ������ �������� ������ ��� ������������

	QVector<Rectangle> input;	// ����
	input << Rectangle(0, 0, 3, 3) << Rectangle(-4, -4, 3, 3);

	QVector<QVector<int>> output;	// ��������� ���������
	QVector<int> line1, line2;
	line1 << 0;	// ��������� ������ ���������
	line2 << 1;	// ��������� ������ ���������
	output << line1 << line2;	// ��������� �����

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "�������������� �� ������������ � ������� �����-c���� �� �������� �������������� - ���� ��������!");
}

testHasIntersectionWithAnother::~testHasIntersectionWithAnother(void)
{
}
