#pragma once
#include <QtTest/QtTest>
#include <QObject>

class TestPasteTogether :
	public QObject
{
Q_OBJECT

public:
	TestPasteTogether(void);
	~TestPasteTogether(void);

	private slots:
		void ifContactOneEdge (void);
		void ifCrossOneEdge (void);
		void ifCrossCorner (void);
		void ifCrossTwoOppositeEdges (void);
		void ifContactOneInOther (void);
		void ifConcurWitnOther (void);
};