//!
//! \file TestHasIntersectionWithAnother.h
//!
#pragma once
#include <QtTest/QtTest>
#include <QObject>

/*!
* \class TestHasIntersectionWithAnother : public QObject
* �������� ����� ��� ������� hasIntersectionWithAnother
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
//! SPLICE_RECTANGLES_EASY_VERSION - ������, ����������� ��� ����������� ������ � ������������ �������� �������
//!
#ifndef SPLICE_RECTANGLES_EASY_VERSION
		//!
		//! �������������� �� �������������, ���� ������� �������
		//!
		void ifNoContactAndOneOutOfOther (void);

		//!
		//! �������������� �� �������������, ���� ������ �������
		//!
		void ifNoContactAndOneInOther (void);

		//!
		//! �������������� ������������� ����� ��������
		//!
		void ifContactOneTop (void);

		//!
		//! �������������� ������������� ����� ������
		//!
		void ifContactOneEdge (void);

		//!
		//! ���� ������������� ���������� ����� �������
		//!
		void ifCrossOneEdge (void);

		//!
		//! ���� ������������� ���������� ��� ������� ����� �������
		//!
		void ifCrossTwoAdjacentEdges (void);

		//!
		//! ���� ������������� ���������� ��� ��������������� ����� �������
		//!
		void ifCrossAnotherThrough (void);

		//!
		//! ���� ������������� ������������� � ������, ���� ������ �������; ���� ��������� � ��� ���������, � ������ ���
		//!
		void ifContactAndOneInOtherAndOneDimensionLess (void);

		//!
		//! ���� ������������� ������������� � ������, ���� ������ �������; ��� ��������� ������ �������������� ������, ��� ��������� �������
		//!
		void ifContactAndOneInOtherAndBothDimensionsLess (void);

		//!
		//! ���� ������������� ������������� � ���������������� ��������� �������, ���� ������ �������; ���� �� ��������� ������� �������������� ������, ��� � �������
		//!
		void ifContactTwoOppositeEdgesAndOneInOther (void);

		//!
		//! �������������� ���������
		//!
		void ifConcurWitnOther (void);
#endif
};