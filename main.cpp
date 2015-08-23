//!
//! \file main.cpp
//!
#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "UnitedRectangles.h"

/*!
* \fn int main(int argc, char *argv[])
* Главная функция
* \param [in] argc - количество аргументов командной строки
* \param [in] argv - аргументы командной строки в виде строк
* \return код завершения программы
*/
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	UnitedRectangles app;				// Открыть доступ к методам класса задачи

	QVector<Rectangle> rectangles;	/**< QVector<Rectangle> rectangles - Вектор многоугольников - вход */
	QVector<QVector<int>> map;		/**< QVector<QVector<Intersection>> map - Двумерный вектор пересечений многоугольников; карта */
	int error = 0;					/**< int error - Код ошибки при проверке входных/выходных данных */
	QVector<Rectangle> result;		/**< QVector<Rectangle> resultEasy - Вектор конечных прямоугольников - результат */

	rectangles = app.readData ();	// Считать многоугольники из файла
	if (rectangles.count() == 0)	// Если нет прямоугольников, то...
	{
		return 1;	// Ошибка
	}

	error = app.correctInput (rectangles);	// Проверить диапазон входных данных
	if (error != 0)	// Если данные вне допустимого диапазона, то...
	{
		return 2;	// Ошибка
	}

	map = app.hasIntersectionWithAhother(rectangles);	// Получить карту пересечений прямоугольников
	app.rebuildMap(map);	// Перестроить карту
	result = app.pasteTogether(rectangles, map);	// Склеить прямоугольники между собой

	error = app.correctOutput(result);	// Проверить диапазон выходных данных
	if (error != 0)	// Если данные вне допустимого диапазона, то...
	{
		return 2;	// Ошибка
	}

	app.writeResult(result);

	return 0;	// Всё нормально
}