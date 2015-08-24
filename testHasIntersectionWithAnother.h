#pragma once
#include <QtTest/QtTest>
#include <QObject>

class testHasIntersectionWithAnother :
	public QObject
{
Q_OBJECT
public:
	testHasIntersectionWithAnother(void);
	~testHasIntersectionWithAnother(void);

	private slots:
		void inSectorIAndContact ();			// ���� j-�� ������������� � ������� i-�� � ��� ������������
		void inSectorIAndNoContact ();			// ���� j-�� ������������� � ������� i-�� � ��� �� ������������
		void inLeftSectorAndContact ();			// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
		void inLeftSectorAndNoContact ();		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
		void inDownSectorAndContact ();			// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
		void inDownSectorAndNoContact ();		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
		void inLeftDownSectorAndContact ();		// ���� j-�� ������������� � ������� ����� �� i-�� � ��� ������������
		void inLeftDownSectorAndNoContact ();	// ���� j-�� ������������� � ������� ����� �� i-�� � ��� �� ������������
};