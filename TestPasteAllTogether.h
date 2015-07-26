#pragma once
#include <QtTest/QtTest>
#include <QObject>

class TestPasteAllTogether :
	public QObject
{
Q_OBJECT

public:
	TestPasteAllTogether(void);
	~TestPasteAllTogether(void);

	private slots:
#ifndef EASY
		void ifNoContact (void);
		void ifIsContact (void);
		void ifIsIntersection (void);
		void ifTwoHavesIntersectionsAndThirdHaveNot (void);
		void ifSevenRectangles (void);
#endif
};
