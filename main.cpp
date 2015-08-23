//!
//! \file main.cpp
//!
#include <QtCore/QCoreApplication>
#include <QtTest/QtTest>
#include "UnitedRectangles.h"

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
	UnitedRectangles app;				// ������� ������ � ������� ������ ������

	QVector<Rectangle> rectangles;	/**< QVector<Rectangle> rectangles - ������ ��������������� - ���� */
	QVector<QVector<int>> map;		/**< QVector<QVector<Intersection>> map - ��������� ������ ����������� ���������������; ����� */
	int error = 0;					/**< int error - ��� ������ ��� �������� �������/�������� ������ */
	QVector<Rectangle> result;		/**< QVector<Rectangle> resultEasy - ������ �������� ��������������� - ��������� */

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

	map = app.hasIntersectionWithAhother(rectangles);	// �������� ����� ����������� ���������������
	app.rebuildMap(map);	// ����������� �����
	result = app.pasteTogether(rectangles, map);	// ������� �������������� ����� �����

	error = app.correctOutput(result);	// ��������� �������� �������� ������
	if (error != 0)	// ���� ������ ��� ����������� ���������, ��...
	{
		return 2;	// ������
	}

	app.writeResult(result);

	return 0;	// �� ���������
}