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
		void inSectorIAndContact ();			// Если j-ый прямоугольник в секторе i-го и они контактируют
		void inSectorIAndNoContact ();			// Если j-ый прямоугольник в секторе i-го и они не контактируют
		void inLeftSectorAndContact ();			// Если j-ый прямоугольник в секторе слева от i-го и они контактируют
		void inLeftSectorAndNoContact ();		// Если j-ый прямоугольник в секторе слева от i-го и они не контактируют
		void inDownSectorAndContact ();			// Если j-ый прямоугольник в секторе снизу от i-го и они контактируют
		void inDownSectorAndNoContact ();		// Если j-ый прямоугольник в секторе снизу от i-го и они не контактируют
		void inLeftDownSectorAndContact ();		// Если j-ый прямоугольник в секторе снизу от i-го и они контактируют
		void inLeftDownSectorAndNoContact ();	// Если j-ый прямоугольник в секторе снизу от i-го и они не контактируют
};