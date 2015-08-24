#pragma once
#include "c:\qt\4.8.6\src\corelib\kernel\qobject.h"
#include <QtTest/QtTest>

class testPasteTogether :
	public QObject
{
Q_OBJECT
public:
	testPasteTogether(void);
	~testPasteTogether(void);

	private slots:
		void secondInLeftDownSector ();		// ������� ������ �������������� �� ������, ������������ �����-����� �������
		void secondInLeftUpSector ();		// ������� ������ �������������� �� ������, ������������ �����-������ �������
		void secondInRightDownSector ();	// ������� ������ �������������� �� ������, ������������ ������-����� �������
		void secondInRightUpSector ();		// ������� ������ �������������� �� ������, ������������ ������-������ �������
		void secondInLeftSector ();			// ������� ������ �������������� �� ������, ������������ ����� �������
		void secondInUpSector ();			// ������� ������ �������������� �� ������, ������������ ������ �������
		void secondInRightSector ();		// ������� ������ �������������� �� ������, ������������ ������ �������
		void secondInDownSector ();			// ������� ������ �������������� �� ������, ������������ ����� �������
};