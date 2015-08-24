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
		void secondInLeftDownSector ();		// Слияние одного прямоугольника со вторым, находящегося слева-снизу первого
		void secondInLeftUpSector ();		// Слияние одного прямоугольника со вторым, находящегося слева-сверху первого
		void secondInRightDownSector ();	// Слияние одного прямоугольника со вторым, находящегося справа-снизу первого
		void secondInRightUpSector ();		// Слияние одного прямоугольника со вторым, находящегося справа-сверху первого
		void secondInLeftSector ();			// Слияние одного прямоугольника со вторым, находящегося слева первого
		void secondInUpSector ();			// Слияние одного прямоугольника со вторым, находящегося сверху первого
		void secondInRightSector ();		// Слияние одного прямоугольника со вторым, находящегося справа первого
		void secondInDownSector ();			// Слияние одного прямоугольника со вторым, находящегося снизу первого
};