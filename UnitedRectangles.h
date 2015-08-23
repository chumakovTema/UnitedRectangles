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
* \class UnitedRectangles
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
	int correctOutput (QVector<Rectangle> & figure);

	//!
	//!	Составление карты пересечений
	//!
	QVector<QVector<int>> hasIntersectionWithAhother (QVector <Rectangle> & rectangles);

	//!
	//! Склейка прямоугольников в новые
	//!
	QVector<Rectangle> pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap);

	//!
	//! Пересборка карты, если в её паралелях есть повторяющиеся элементы
	//!
	void rebuildMap (QVector<QVector<int>> & map);

	//!
	//! Запись полученных прямоугольников в файл
	//!
	void writeResult (QVector<Rectangle>  & newFigures);
};

//!
//! Перегруженная операция чтения из текстового потока
//!
QTextStream & operator >> (QTextStream & in, Rectangle & other);

//!
//! Перегруженная операция записи в текстовый поток
//!
QTextStream & operator << (QTextStream & out, const QPoint & other);