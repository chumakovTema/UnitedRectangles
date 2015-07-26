#pragma once
#include <QVector>
#include <QList>
#include <QPoint>
#include <QTextStream>
#include <QFile>
#include "Rectangle.h"
#include "Intersection.h"

class UnitedRectangles
{
public:
	UnitedRectangles(void);
	~UnitedRectangles(void);

	QVector <Rectangle> readData ();		// Чтение данных из файла
	QVector<QPoint> getTops (Rectangle it);	// Получение координат всех вершин прямоугольника

#ifdef EASY	// Компиляция лёгкого решения
	Rectangle pasteAllTogetherEasy (QVector<Rectangle> & rectangles);	// Склейка прямоугольников в один
	void writeResultEasy (Rectangle & figure);							// Запись данных в файл
#else		// Компиляция сложного решения, режима отладки или тестового режима
	QVector<QVector<QPoint>> pasteAllTogether (QVector<Rectangle> & rectangles);
	QVector<QVector<Intersection>> hasIntersectionWithAhother (Rectangle first, int num1, Rectangle other, int num2);
	QVector<QVector<QPoint>> pasteTogether (QVector<QVector<Intersection>> & intersections, const int count);
	void writeResult (QVector<QVector<QPoint>> & figures);			// Запись данных в файл
#endif
};

QTextStream & operator >> (QTextStream & in, Rectangle & other);
QTextStream & operator << (QTextStream & out, const QPoint & other);