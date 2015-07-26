#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "UnitedRectangles.h"
#include "TestHasIntersectionWithAnother.h"
#include "TestPasteTogether.h"
#include "TestPasteAllTogether.h"

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

	UnitedRectangles app;	// Открыть доступ к методам класса задачи
	QVector<Rectangle> rectangles;		// Вектор многоугольников - вход
	QVector<QVector<QPoint>> result;	// Вектор фигур - результат

	rectangles = app.readData ();	// Считать многоугольники из файла

	result = app.pasteAllTogether (rectangles);	// Получить список объединённых прямоугольников

	app.writeResult (result);		// Записать результат в файл

	return 0;
}