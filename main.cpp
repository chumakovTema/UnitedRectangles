//!
//! \file main.cpp
//!
#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "UnitedRectangles.h"
#include "TestHasIntersectionWithAnother.h"
#include "TestPasteTogether.h"
#include "TestPasteAllTogether.h"

//!
//! SPLICE_RECTANGLES_EASY_VERSION - макрос, открывающий или закрывающий доступ к облегчённому варианту решения
//!

//!
//! TEST - макрос, открывающий доступ к модульному тестированию.
//!

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

#ifdef TEST
	TestHasIntersectionWithAnother first;
	QTest::qExec (&first);

	TestPasteTogether second;
	QTest::qExec (&second);

	TestPasteAllTogether third;
	QTest::qExec (&third);

	return 0;
#endif

	UnitedRectangles app;			// Открыть доступ к методам класса задачи
	QVector<Rectangle> rectangles;	/**< QVector<Rectangle> rectangles - Вектор многоугольников - вход */
	int error = 0;

#ifdef SPLICE_RECTANGLES_EASY_VERSION
	Rectangle resultEasy;		/**< Rectangle resultEasy - Конечный прямоугольник - результат */

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

	resultEasy = app.pasteAllTogetherEasy (rectangles);	// Склеить все прямоугольники в один
	error = app.correctOutput (resultEasy);
	if (error != 0)	// Если странные выходные данные, то...
	{
		return 3;	// Ошибка
	}

	app.writeResultEasy (resultEasy);	// Записать результат в файл

	return 0;	// Всё нормально
#else
	QVector<QVector<QPoint>> result;/**< QVector<QVector<QPoint>> - Вектор фигур - результат */

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

	result = app.pasteAllTogether (rectangles);	// Получить список объединённых прямоугольников
	app.writeResult (result);		// Записать результат в файл

	return 0;
#endif
}