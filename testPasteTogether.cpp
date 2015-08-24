#include "testPasteTogether.h"
#include "UnitedRectangles.h"

testPasteTogether::testPasteTogether(void)
{
}

void testPasteTogether::secondInLeftDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, -2, 3, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, -2, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в левом-нижнем секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInLeftUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, 2, 3, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, 0, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в левом-верхнем секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInRightDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, -2, 3, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, -2, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в правом-нижнем секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInRightUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, 2, 3, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 5, 5);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в правом-верхнем секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInLeftSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 4, 4) << Rectangle(-2, 1, 3, 2);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(-2, 0, 6, 4);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в левом секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInUpSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 4, 4) << Rectangle(1, 3, 2, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 4, 6);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в верхнем секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInRightSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 4, 4) << Rectangle(3, 1, 3, 2);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, 0, 6, 4);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в правом секторе с первым прямоугольником - тест провален!");
}

void testPasteTogether::secondInDownSector ()
{
	UnitedRectangles test;

	QVector<Rectangle> input;	// Входной вектор прямоугольников
	input << Rectangle(0, 0, 4, 4) << Rectangle(1, -2, 2, 3);

	QVector<QVector<int>> map;	// Входная карта пересечений
	QVector<int> line;
	line << 0 << 1;
	map << line;

	QVector<Rectangle> output;
	output << Rectangle(0, -2, 4, 6);

	QVERIFY2(test.pasteTogether(input, map) == output, "Слияние прямоугольника в нижнем секторе с первым прямоугольником - тест провален!");
}

testPasteTogether::~testPasteTogether(void)
{
}
