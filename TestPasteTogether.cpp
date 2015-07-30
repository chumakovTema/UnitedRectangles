#include "TestPasteTogether.h"
#include "UnitedRectangles.h"
#include <QVector>
#include <QPoint>
#include <QList>

TestPasteTogether::TestPasteTogether(void)
{
}

TestPasteTogether::~TestPasteTogether(void)
{
}

#ifndef SPLICE_RECTANGLES_EASY_VERSION
void TestPasteTogether::ifContactOneEdge (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-3, 2) << QPoint(-1, 2) << QPoint(-1, 1) << QPoint(2, 1) << QPoint(2, -1) << QPoint(-1, -1) << QPoint(-1, -2) << QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-1, 1) << QPoint(-1, -1);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-1, 1) << QPoint(-1, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Прямоугольники соприкасаются одной стороной - тест не пройден!");
}

void TestPasteTogether::ifCrossOneEdge (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-1, 2) << QPoint(0, 2) << QPoint(0, -1) << QPoint(1, -1) << QPoint(1, -3) << QPoint(-2, -3) << QPoint(-2, -1) << QPoint(-1, -1);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-1, -1) << QPoint(0, -1);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-1, -1) << QPoint(0, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Один прямоугольник пересекает сторону другого, с которой имеет две общих точки - тест не пройден!");
}

void TestPasteTogether::ifCrossCorner (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-3, 1) << QPoint(-1, 1) << QPoint(-1, 2) << QPoint(3, 2) << QPoint(3, -1) << QPoint(1, -1) << QPoint(1, -2) << QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-1, 1) << QPoint(1, -1);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-1, 1) << QPoint(1, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Один прямоугольник пересекает угол другого и имеет с его двумя смежными сторонами по одной общей точке - тест не пройден!");
}

void TestPasteTogether::ifCrossTwoOppositeEdges (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-3, 2) << QPoint(-2, 2) << QPoint(-2, 3) << QPoint(2, 3) << QPoint(2, 2) << QPoint(3, 2) << QPoint(3, -2) << QPoint(2, -2) << QPoint(2, -3) << QPoint(-2, -3) << QPoint(-2, -2) << QPoint(-3, -2);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-2, 2) << QPoint(2, 2) << QPoint(2, -2) << QPoint(-2, -2);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-2, 2) << QPoint(2, 2) << QPoint(2, -2) << QPoint(-2, -2);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Один прямоугольник пересекает обе противоположные стороны другого и имеет с ним четыре общих точки - тест не пройден!");
}

void TestPasteTogether::ifContactOneInOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-2, 2) << QPoint(1, 2) << QPoint(1, -3) << QPoint(-2, -3);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-2, 2) << QPoint(0, 2) << QPoint(2, -1);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-2, 2) << QPoint(0, 2) << QPoint(2, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Прямоугольники соприкасаются, один прямоугольник находится внутри второго - тест не пройден!");
}

void TestPasteTogether::ifConcurWitnOther (void)
{
	UnitedRectangles app;	// Открыть доступ к методам тестируемого класса

	QVector<QVector<QPoint>> points;	// Эталонные данные
	QVector<QPoint> map;	// Результат объединения
	map << QPoint(-2, 2) << QPoint(2, 2) << QPoint(2, -1) << QPoint(-2, -1);
	points.append(map);

	QVector<QVector<Intersection>> data;	// Входные данные
	QVector<Intersection> intersections1, intersections2;// Карта пересечений
	Intersection map1, map2;

	QList <QPoint> list;// Подготовить список точек

	list.clear();		// Опустошить список
	list << QPoint(-2, 2) << QPoint(2, 2) << QPoint(2, -1) << QPoint(-2, -1);
	map1 = Intersection(0, 1, true, list);	// Подготовить карту пересечений
	intersections1.append(map1);

	list.clear();
	list << QPoint(-2, 2) << QPoint(2, 2) << QPoint(2, -1) << QPoint(-2, -1);
	map2 = Intersection(1, 0, true, list);
	intersections2.append(map2);

	data << intersections1 << intersections2;	// Положить её в двумерный вектор
	const int count = 2;

	QVERIFY2(app.pasteTogether(data, count) == points, "Прямоугольники совпадают - тест не пройден!");
}
#endif