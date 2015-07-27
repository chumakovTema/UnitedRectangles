//!
//! \file main.cpp
//!
#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "UnitedRectangles.h"
#include "TestHasIntersectionWithAnother.h"
#include "TestPasteTogether.h"
#include "TestPasteAllTogether.h"

/*!
* \fn int main(int argc, char *argv[])
* ������� �������
* \param [in] argc - ���������� ���������� ��������� ������
* \param [in] argv - ��������� ��������� ������ � ���� �����
* \return ��� ���������� ���������
*/
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

//!
//! TEST - ������, ����������� ������ � ���������� ������������.
//!
#ifdef TEST
	TestHasIntersectionWithAnother first;
	QTest::qExec (&first);

	TestPasteTogether second;
	QTest::qExec (&second);

	TestPasteAllTogether third;
	QTest::qExec (&third);

	return 0;
#endif

	UnitedRectangles app;			// ������� ������ � ������� ������ ������
	QVector<Rectangle> rectangles;	/**< QVector<Rectangle> rectangles - ������ ��������������� - ���� */

//!
//! SPLICE_RECTANGLES_EASY_VERSION - ������, ����������� ��� ����������� ������ � ������������ �������� �������
//!
#ifdef SPLICE_RECTANGLES_EASY_VERSION
	Rectangle resultEasy;		/**< Rectangle resultEasy - �������� ������������� - ��������� */

	rectangles = app.readData ();		// ������� �������������� �� �����
	resultEasy = app.pasteAllTogetherEasy (rectangles);	// ������� ��� �������������� � ����
	app.writeResultEasy (resultEasy);	// �������� ��������� � ����

	return 0;
#else
	QVector<QVector<QPoint>> result;/**< QVector<QVector<QPoint>> - ������ ����� - ��������� */

	rectangles = app.readData ();	// ������� �������������� �� �����
	result = app.pasteAllTogether (rectangles);	// �������� ������ ����������� ���������������
	app.writeResult (result);		// �������� ��������� � ����

	return 0;
#endif
}