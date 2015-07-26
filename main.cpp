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

	UnitedRectangles app;	// ������� ������ � ������� ������ ������
	QVector<Rectangle> rectangles;		// ������ ��������������� - ����
	QVector<QVector<QPoint>> result;	// ������ ����� - ���������

	rectangles = app.readData ();	// ������� �������������� �� �����

	result = app.pasteAllTogether (rectangles);	// �������� ������ ����������� ���������������

	app.writeResult (result);		// �������� ��������� � ����

	return 0;
}