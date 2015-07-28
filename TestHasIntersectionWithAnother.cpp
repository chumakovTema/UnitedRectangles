#include "TestHasIntersectionWithAnother.h"
#include "UnitedRectangles.h"

#ifndef SPLICE_RECTANGLES_EASY_VERSION
TestHasIntersectionWithAnother::TestHasIntersectionWithAnother(void)
{
}

void TestHasIntersectionWithAnother::ifNoContactAndOneOutOfOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-3, -2, 2, 4);	// Ввести параметры для первого прямоугольника
	second = Rectangle (1, -1, 2, 3);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;// Подготовить список точек
	list.clear();	// Опустошить список

	map = Intersection(0, 1, false, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники не соприкасаются, один находится снаружи другого - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifNoContactAndOneInOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, -2, 4, 4);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-1, -1, 2, 2);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;// Подготовить список точек
	list.clear();	// Опустошить список

	map = Intersection(0, 1, false, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники не соприкасаются, один находится внутри другого - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifContactOneTop (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-3, 0, 3, 1);	// Ввести параметры для первого прямоугольника
	second = Rectangle (0, -2, 1, 2);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(0, 0);	// Положить точки контакта в список

	map = Intersection(0, 1, false, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, но у них общая только одна вершина - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifContactOneEdge (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, 1, 3, 2);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-1, -1, 3, 2);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, 1);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, часть или целая сторона одного прямоугольника является общей для второго - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifCrossOneEdge (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, -2, 3, 5);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-1, -1, 4, 3);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(1, -1) << QPoint::QPoint(1, 2);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники пересекаются, одна из сторон одного прямоугольника рассекает второй на две части - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifCrossTwoAdjacentEdges (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-3, -2, 4, 3);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-1, -1, 3, 3);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-1, 1) << QPoint::QPoint(1, -1);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники пересекаются, один прямоугольник пересекает две смежные стороны другого - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifCrossAnotherThrough (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-3, -1, 5, 2);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-2, -2, 2, 4);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-2, 1) << QPoint::QPoint(0, 1) << QPoint::QPoint(0, -1) << QPoint::QPoint(-2, -1);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники пересекаются, один прямоугольник пересекает обе стороны второго и рассекает его на три части - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifContactAndOneInOtherAndOneDimensionLess (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, -3, 3, 4);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-2, -3, 3, 2);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-2, -1) << QPoint::QPoint(1, -1) << QPoint::QPoint(1, -3) << QPoint::QPoint(-2, -3);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, один прямоугольник находится внутри второго, одно измерение обоих прямоугольников совпадает, а второе измерение у одного из прямоугольников меньше, чем у второго - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifContactAndOneInOtherAndBothDimensionsLess (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, -1, 5, 4);	// Ввести параметры для первого прямоугольника
	second = Rectangle (0, 0, 3, 3);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(0, 3) << QPoint::QPoint(3, 3) << QPoint::QPoint(3, 0);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, один прямоугольник находится внутри другого, но у одного прямоугольника оба измерения меньше, чем у второго - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifContactTwoOppositeEdgesAndOneInOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-3, -2, 5, 4);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-1, -2, 2, 4);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-1, 2) << QPoint::QPoint(1, 2) << QPoint::QPoint(1, -2) << QPoint::QPoint(-1, -2);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, один находится внутри другого, противоположные стороны одного прямоугольника являются общими для соответствующих сторон другого - тест не пройден!");
}

void TestHasIntersectionWithAnother::ifConcurWitnOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	Rectangle first;	// Первый прямоугольник
	Rectangle second;	// Второй прямоугольник

	first = Rectangle (-2, -1, 3, 3);	// Ввести параметры для первого прямоугольника
	second = Rectangle (-2, -1, 3, 3);	// Ввести параметры для второго прямоугольника

	QVector<QVector<Intersection>> data;// Эталонные данные
	QVector<Intersection> intersections;// Карта пересечений
	Intersection map;

	QList <QPoint> list;	// Подготовить список точек
	list.clear();			// Опустошить список
	list << QPoint::QPoint(-2, -1) << QPoint::QPoint(-2, 2) << QPoint::QPoint(1, 2) << QPoint::QPoint(1, -1);	// Положить точки контакта в список

	map = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections.append(map);
	data.append(intersections);	// Положить её в двумерный вектор

	QVERIFY2(app.hasIntersectionWithAhother(first, 0, second, 1) == data, "Прямоугольники соприкасаются, один находится внутри другого, противоположные стороны одного прямоугольника являются общими для соответствующих сторон другого - тест не пройден!");
}

TestHasIntersectionWithAnother::~TestHasIntersectionWithAnother(void)
{
}
#endif