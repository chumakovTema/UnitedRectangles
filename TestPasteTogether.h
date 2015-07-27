//!
//! \file TestPasteTogether.h
//!
#pragma once
#include <QtTest/QtTest>
#include <QObject>

/*!
* \class TestPasteTogether : public QObject
* Тестовый класс для функции pasteTogether
*/
class TestPasteTogether :
	public QObject
{
Q_OBJECT

public:
	TestPasteTogether(void);
	~TestPasteTogether(void);

	private slots:
//!
//! SPLICE_RECTANGLES_EASY_VERSION - макрос, открывающий или закрывающий доступ к облегчённому варианту решения
//!
#ifndef SPLICE_RECTANGLES_EASY_VERSION
		//!
		//! Прямоугольники соприкасаются одной гранью
		//!
		void ifContactOneEdge (void);

		//!
		//! Один прямоугольник пересекает одну грань другого
		//!
		void ifCrossOneEdge (void);

		//!
		//! Один прямоугольник пересекает две смежных грани другого
		//!
		void ifCrossCorner (void);

		//!
		//! Один прямоугольник пересекает две противоположных грани другого
		//!
		void ifCrossTwoOppositeEdges (void);

		//!
		//! Прямоугольники соприкасаются, один внутри другого
		//!
		void ifContactOneInOther (void);

		//!
		//! Прямоугольники совпадают
		//!
		void ifConcurWitnOther (void);
#endif
};