//!
//! \file TestPasteAllTogether.h
//!
#pragma once
#include <QtTest/QtTest>
#include <QObject>

/*!
* \class TestPasteAllTogether : public QObject
* Тестовый класс для функции pasteAllTogether
*/
class TestPasteAllTogether :
	public QObject
{
Q_OBJECT

public:
	TestPasteAllTogether(void);
	~TestPasteAllTogether(void);

	private slots:
//!
//! SPLICE_RECTANGLES_EASY_VERSION - макрос, открывающий или закрывающий доступ к облегчённому варианту решения
//!
#ifndef SPLICE_RECTANGLES_EASY_VERSION
		//!
		//! Прямоугольники не соприкасаются
		//!
		void ifNoContact (void);

		//!
		//! Прямоугольники соприкасаются
		//!
		void ifIsContact (void);

		//!
		//! Прямоугольники пересекаются
		//!
		void ifIsIntersection (void);

		//!
		//! Два прямоугольника пересекаются, а третий с ними не пересекается
		//!
		void ifTwoHavesIntersectionsAndThirdHaveNot (void);

		//!
		//! Семь прямоугольников взаимодействуют между собой разными способами
		//!
		void ifSevenRectangles (void);
#endif
};
