//!
//! \file TestHasIntersectionWithAnother.h
//!
#pragma once
#include <QtTest/QtTest>
#include <QObject>

/*!
* \class TestHasIntersectionWithAnother : public QObject
* Тестовый класс для функции hasIntersectionWithAnother
*/
class TestHasIntersectionWithAnother :
	public QObject
{
Q_OBJECT

public:
	TestHasIntersectionWithAnother(void);
	~TestHasIntersectionWithAnother(void);

	private slots:
//!
//! SPLICE_RECTANGLES_EASY_VERSION - макрос, открывающий или закрывающий доступ к облегчённому варианту решения
//!
#ifndef SPLICE_RECTANGLES_EASY_VERSION
		//!
		//! Прямоугольники не соприкасаются, один снаружи другого
		//!
		void ifNoContactAndOneOutOfOther (void);

		//!
		//! Прямоугольники не соприкасаются, один внутри другого
		//!
		void ifNoContactAndOneInOther (void);

		//!
		//! Прямоугольники соприкасаются одной вершиной
		//!
		void ifContactOneTop (void);

		//!
		//! Прямоугольники соприкасаются одной гранью
		//!
		void ifContactOneEdge (void);

		//!
		//! Один прямоугольник пересекает грань другого
		//!
		void ifCrossOneEdge (void);

		//!
		//! Один прямоугольник пересекает две смежные грани другого
		//!
		void ifCrossTwoAdjacentEdges (void);

		//!
		//! Один прямоугольник пересекает две противоположные грани другого
		//!
		void ifCrossAnotherThrough (void);

		//!
		//! Один прямоугольник соприкасается с другим, один внутри другого; одно измерение у них совпадает, а второе нет
		//!
		void ifContactAndOneInOtherAndOneDimensionLess (void);

		//!
		//! Один прямоугольник соприкасается с другим, один внутри другого; оба измерения одного прямоугольника меньше, чем измерения второго
		//!
		void ifContactAndOneInOtherAndBothDimensionsLess (void);

		//!
		//! Один прямоугольник соприкасается с противоположными сторонами другого, один внутри другого; одно из измерений первого прямоугольника меньше, чем у второго
		//!
		void ifContactTwoOppositeEdgesAndOneInOther (void);

		//!
		//! Прямоугольники совпадают
		//!
		void ifConcurWitnOther (void);
#endif
};