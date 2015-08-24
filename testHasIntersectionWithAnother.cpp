#include "testHasIntersectionWithAnother.h"
#include "UnitedRectangles.h"

testHasIntersectionWithAnother::testHasIntersectionWithAnother(void)
{
}

void testHasIntersectionWithAnother::inSectorIAndContact ()
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, 2, 3, 3);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line;
	line << 0 << 1;	// Заполнить параллель
	output << line;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники пересекаются в секторе нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inSectorIAndNoContact ()
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(4, 2, 3, 3);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line1, line2;
	line1 << 0;	// Заполнить первую параллель
	line2 << 1;	// Заполнить вторую параллель
	output << line1 << line2;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники не пересекаются в секторе нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inLeftSectorAndContact ()		// Если j-ый прямоугольник в секторе слева от i-го и они контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(-3, 1, 4, 2);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line;
	line << 0 << 1;	// Заполнить параллель
	output << line;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники не пересекаются в секторе слева от нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inLeftSectorAndNoContact ()	// Если j-ый прямоугольник в секторе слева от i-го и они не контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(-4, 2, 3, 2);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line1, line2;
	line1 << 0;	// Заполнить первую параллель
	line2 << 1;	// Заполнить вторую параллель
	output << line1 << line2;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники не пересекаются в секторе слева от нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inDownSectorAndContact ()		// Если j-ый прямоугольник в секторе снизу от i-го и они контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(1, -2, 1, 3);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line;
	line << 0 << 1;	// Заполнить параллель
	output << line;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники пересекаются в секторе снизу от нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inDownSectorAndNoContact ()	// Если j-ый прямоугольник в секторе снизу от i-го и они не контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(2, -3, 3, 2);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line1, line2;
	line1 << 0;	// Заполнить первую параллель
	line2 << 1;	// Заполнить вторую параллель
	output << line1 << line2;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники не пересекаются в секторе cнизу от нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inLeftDownSectorAndContact ()		// Если j-ый прямоугольник в секторе снизу от i-го и они контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(-2, -2, 3, 3);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line;
	line << 0 << 1;	// Заполнить параллель
	output << line;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники пересекаются в секторе слева-снизу от нулевого прямоугольника - тест провален!");
}

void testHasIntersectionWithAnother::inLeftDownSectorAndNoContact ()	// Если j-ый прямоугольник в секторе снизу от i-го и они не контактируют
{
	UnitedRectangles test;	// Открыть методы целевого класса для тестирования

	QVector<Rectangle> input;	// Вход
	input << Rectangle(0, 0, 3, 3) << Rectangle(-4, -4, 3, 3);

	QVector<QVector<int>> output;	// Эталонный результат
	QVector<int> line1, line2;
	line1 << 0;	// Заполнить первую параллель
	line2 << 1;	// Заполнить вторую параллель
	output << line1 << line2;	// Заполнить карту

	QVERIFY2(test.hasIntersectionWithAhother(input) == output, "Прямоугольники не пересекаются в секторе слева-cнизу от нулевого прямоугольника - тест провален!");
}

testHasIntersectionWithAnother::~testHasIntersectionWithAnother(void)
{
}
