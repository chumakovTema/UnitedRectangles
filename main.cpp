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
//! SPLICE_RECTANGLES_EASY_VERSION - ������, ����������� ��� ����������� ������ � ������������ �������� �������
//!

//!
//! TEST - ������, ����������� ������ � ���������� ������������.
//!

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
	int error = 0;

#ifdef SPLICE_RECTANGLES_EASY_VERSION
	Rectangle resultEasy;		/**< Rectangle resultEasy - �������� ������������� - ��������� */

	rectangles = app.readData ();	// ������� �������������� �� �����
	if (rectangles.count() == 0)	// ���� ��� ���������������, ��...
	{
		return 1;	// ������
	}

	error = app.correctInput (rectangles);	// ��������� �������� ������� ������
	if (error != 0)	// ���� ������ ��� ����������� ���������, ��...
	{
		return 2;	// ������
	}

	resultEasy = app.pasteAllTogetherEasy (rectangles);	// ������� ��� �������������� � ����
	error = app.correctOutput (resultEasy);
	if (error != 0)	// ���� �������� �������� ������, ��...
	{
		return 3;	// ������
	}

	app.writeResultEasy (resultEasy);	// �������� ��������� � ����

	return 0;	// �� ���������
#else
	QVector<QVector<QPoint>> result;/**< QVector<QVector<QPoint>> - ������ ����� - ��������� */

	rectangles = app.readData ();	// ������� �������������� �� �����
	if (rectangles.count() == 0)	// ���� ��� ���������������, ��...
	{
		return 1;	// ������
	}

	error = app.correctInput (rectangles);	// ��������� �������� ������� ������
	if (error != 0)	// ���� ������ ��� ����������� ���������, ��...
	{
		return 2;	// ������
	}

	result = app.pasteAllTogether (rectangles);	// �������� ������ ����������� ���������������
	app.writeResult (result);		// �������� ��������� � ����

	return 0;
#endif
}