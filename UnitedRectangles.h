//!
//! \file UnitedRectangles.h
//!
#pragma once
#include <QVector>
#include <QList>
#include <QPoint>
#include <QTextStream>
#include <QFile>
#include "Rectangle.h"
#include "Intersection.h"

/*!
* class UnitedRectangles
* Рабочий класс
*/
class UnitedRectangles
{
public:
	UnitedRectangles(void);
	~UnitedRectangles(void);

	//!
	//! Чтение данных из файла
	//!
	QVector <Rectangle> readData ();

	//!
	//! Получение координат всех вершин прямоугольника
	//!
	QVector<QPoint> getTops (Rectangle it);

	//!
	//! Проверка диапазона входных данных
	//!
	int correctInput (QVector <Rectangle> & rectangles);

	//!
	//! Проверка диапазона выходных данных
	//!
	int correctOutput (Rectangle  & figure);

#ifdef SPLICE_RECTANGLES_EASY_VERSION	// Компиляция лёгкого решения
	//!
	//! Склейка прямоугольников в один
	//!
	Rectangle pasteAllTogetherEasy (QVector<Rectangle> & rectangles);

	//!
	//! Запись данных в файл
	//!
	void writeResultEasy (Rectangle & figure);
#else		// Компиляция сложного решения, режима отладки или тестового режима
	//!
	//! Склейка прямоугольников в одну фигуру
	//!
	QVector<QVector<QPoint>> pasteAllTogether (QVector<Rectangle> & rectangles);

	//!
	//! Получение карты пересечений прямоугольников
	//!
	QVector<QVector<Intersection>> hasIntersectionWithAhother (Rectangle first, int num1, Rectangle other, int num2);

	//!
	//! Склейка двух прямоугольников
	//!
	QVector<QVector<QPoint>> pasteTogether (QVector<QVector<Intersection>> & intersections, const int count);

	//!
	//! Запись данных в файл
	//!
	void writeResult (QVector<QVector<QPoint>> & figures);
#endif
};

//!
//! Перегруженная операция чтения из текстового потока
//!
QTextStream & operator >> (QTextStream & in, Rectangle & other);

//!
//! Перегруженная операция записи в текстовый поток
//!
QTextStream & operator << (QTextStream & out, const QPoint & other);