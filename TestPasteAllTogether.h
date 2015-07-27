//!
//! \file TestPasteAllTogether.h
//!
#pragma once
#include <QtTest/QtTest>
#include <QObject>

/*!
* \class TestPasteAllTogether : public QObject
* �������� ����� ��� ������� pasteAllTogether
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
//! SPLICE_RECTANGLES_EASY_VERSION - ������, ����������� ��� ����������� ������ � ������������ �������� �������
//!
#ifndef SPLICE_RECTANGLES_EASY_VERSION
		//!
		//! �������������� �� �������������
		//!
		void ifNoContact (void);

		//!
		//! �������������� �������������
		//!
		void ifIsContact (void);

		//!
		//! �������������� ������������
		//!
		void ifIsIntersection (void);

		//!
		//! ��� �������������� ������������, � ������ � ���� �� ������������
		//!
		void ifTwoHavesIntersectionsAndThirdHaveNot (void);

		//!
		//! ���� ��������������� ��������������� ����� ����� ������� ���������
		//!
		void ifSevenRectangles (void);
#endif
};
