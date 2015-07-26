#include "UnitedRectangles.h"

UnitedRectangles::UnitedRectangles(void)
{
}

QTextStream & operator >> (QTextStream & in, Rectangle & other)
{
	in >> other.x >> other.y >> other.length >> other.width;

	return in;
}

QTextStream & operator << (QTextStream & out, const QPoint & other)
{
	out << "(" << other.x() << other.y() << ")";

	return out;
}

QVector <Rectangle> UnitedRectangles::readData ()
{
	QVector <Rectangle> data;
	int count = 0;

	QFile file ("target.txt");			// ������� ���� � ��� ������
	if (file.open(QIODevice::ReadOnly))	// ���� ������� �������, ��...
	{
		QTextStream In (&file);		// ������� �������� �����
		In >> count;				// ������� ���������� ���������������

		for (int i = 1; i < count; i++)	// ������� ������ �������������
		{
			Rectangle temp;
			In >> temp;
			data.append(temp);	// �������� ������������� � ������
		}
		file.close();			// ������� ����
	}

	return data;
}

Rectangle UnitedRectangles::pasteAllTogetherEasy (QVector<Rectangle> & rectangles)
{
	Rectangle result;

	QVector <QPoint> points;
	QPoint A = QPoint::QPoint(rectangles.at(0).x, rectangles.at(0).y);
	QPoint B = QPoint::QPoint(rectangles.at(0).x + rectangles.at(0).length, rectangles.at(0).y);
	QPoint C = QPoint::QPoint(rectangles.at(0).x, rectangles.at(0).y + rectangles.at(0).width);
	QPoint D = QPoint::QPoint(rectangles.at(0).x + rectangles.at(0).length, rectangles.at(0).y + rectangles.at(0).width);

	for (int i = 0; i < rectangles.count(); i++)
	{
		if (rectangles.at(i).x < A.x())
		{
			A.setX(rectangles.at(i).x);
			if (rectangles.at(i).y < A.y())
			{
				A.setY(rectangles.at(i).y);
			}
		}
		if (rectangles.at(i).x + rectangles.at(i).length > B.x())
		{
			B.setX(rectangles.at(i).x + rectangles.at(i).length);
			if (rectangles.at(i).y < B.y())
			{
				B.setY(rectangles.at(i).y);
			}
		}
		if (rectangles.at(i).x < C.x())
		{
			C.setX(rectangles.at(i).x);
			if (rectangles.at(i).y + rectangles.at(i).width > C.y())
			{
				C.setY(rectangles.at(i).y + rectangles.at(i).width);
			}
		}
		if (rectangles.at(i).x + rectangles.at(i).length > D.x())
		{
			D.setX(rectangles.at(i).x + rectangles.at(i).length);
			if (rectangles.at(i).y + rectangles.at(i).width > D.y())
			{
				D.setY(rectangles.at(i).y + rectangles.at(i).width);
			}
		}
	}

	points << A << B << C << D;
	int Xmin = 0;
	int Ymin = 0;
	int Xmax = 0;
	int Ymax = 0;
	for (int i = 0; i < 4; i++)
	{
		if (points.at(i).x() < Xmin)
		{
			Xmin = points.at(i).x();
		}
		if (points.at(i).y() < Ymin)
		{
			Ymin = points.at(i).y();
		}
		if (points.at(i).x() > Xmax)
		{
			Xmax = points.at(i).x();
		}
		if (points.at(i).y() > Ymax)
		{
			Ymax = points.at(i).y();
		}
	}

	result.x = Xmin;
	result.y = Ymin;
	result.length = Xmax - Xmin;
	result.width = Ymax - Ymin;

	return result;
}

QVector<QVector<QPoint>> UnitedRectangles::pasteAllTogether (QVector<Rectangle> & rectangles)
{
	QVector<QVector<QPoint>> figures;

	int count = rectangles.count();
	QVector<QVector<Intersection>> intersections;

	for (int i = 0; i < count; i++)	// ��� ������� ��������������...
	{
		for (int j = 0; j < count; j++)	// ����� �������� �������...
		{
			if (i != j)	// ���� ����� ������� �� ��������� � ������� �������...
			{
				intersections = hasIntersectionWithAhother (rectangles.at(i), i, rectangles.at(j), j);// ����� �����������
			}
		}

		figures = pasteTogether (intersections, count);	// ������� �������������� // � ����� �� ��� ��������???
	}

	return figures;
}

QVector<QPoint> UnitedRectangles::getTops (Rectangle it)
{
	// �������� ������� ������� ��������������
	QVector <QPoint> tops;
	QPoint first, second, third, fourth;

	first = QPoint::QPoint (it.x, it.y);
	second = QPoint::QPoint (it.x + it.length, it.y);
	third = QPoint::QPoint (it.x, it.y + it.width);
	fourth = QPoint::QPoint (it.x + it.length, it.y + it.width);

	tops << first << second << third << fourth;
	return tops;
}

QVector<QVector<Intersection>> UnitedRectangles::hasIntersectionWithAhother (Rectangle first, int current, Rectangle other, int second)
{
	QVector<QVector<Intersection>> map;	// ����� �����������
	QVector<Intersection> line;

	QVector <QPoint> firstRec;
	QVector <QPoint> secondRec;
	firstRec = getTops (first);		// �������� ������� ������� ��������������
	secondRec = getTops (other);	// �������� ������� ������� ��������������

	// �������� �����������
	if ((secondRec.at(0).x() > firstRec.at(0).x() && secondRec.at(0).y() > firstRec.at(0).y()) && (secondRec.at(3).x() < firstRec.at(3).x() && secondRec.at(3).y() < firstRec.at(3).y())) // ������ ������ �������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = false;
		temp.intersection.clear();

		line << temp;
		map << line;
	}
	else if (secondRec.at(0).x() > firstRec.at(1).x() || secondRec.at(0).y() > firstRec.at(3).y() || secondRec.at(3).x() < firstRec.at(0).x() || secondRec.at(3).y() < firstRec.at(0).y())	// ������ ��� �������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = false;
		temp.intersection.clear();

		line << temp;
		map << line;
	}
	else if (secondRec.at(0) == firstRec.at(0) && other.length < first.length && other.width < first.width) // ����� ������ ���� �������������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec.at(0).x(), firstRec.at(0).y()) << QPoint::QPoint(secondRec.at(1).x(), firstRec.at(0).y()) << QPoint::QPoint(firstRec.at(0).x(), secondRec.at(2).y());

		line << temp;
		map << line;
	}
	else if (secondRec.at(1) == firstRec.at(1) && other.length < first.length && other.width < first.width) // ������ ������ ���� �������������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(secondRec.at(0).x(), firstRec.at(1).y()) << QPoint::QPoint(firstRec.at(1).x(), firstRec.at(1).y()) << QPoint::QPoint(firstRec.at(1).x(), secondRec.at(3).y());

		line << temp;
		map << line;
	}
	else if (secondRec.at(2) == firstRec.at(2) && other.length < first.length && other.width < first.width) // ����� ������� ���� �������������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec.at(2).x(), secondRec.at(0).y()) << QPoint::QPoint(firstRec.at(2).x(), firstRec.at(2).y()) << QPoint::QPoint(secondRec.at(3).x(), firstRec.at(2).y());

		line << temp;
		map << line;
	}
	else if (secondRec.at(3) == firstRec.at(3) && other.length < first.length && other.width < first.width) // ������ ������� ���� �������������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec.at(3).x(), secondRec.at(1).y()) << QPoint::QPoint(secondRec.at(2).x(), firstRec.at(3).y()) << QPoint::QPoint(firstRec.at(3).x(), firstRec.at(3).y());

		line << temp;
		map << line;
	}
	else if (secondRec.at(0).x() == firstRec.at(0).x() && secondRec.at(0).y() > firstRec.at(0).y() && other.length == first.length && other.width < (first.width - (secondRec.at(0).y() - firstRec.at(0).y()) - (firstRec.at(3).y() - secondRec.at(3).y()))) // ������ ������� ���� �������������
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec.at(3).x(), secondRec.at(1).y()) << QPoint::QPoint(secondRec.at(2).x(), firstRec.at(3).y()) << QPoint::QPoint(firstRec.at(3).x(), firstRec.at(3).y());

		line << temp;
		map << line;
	}

	return map;
}

QVector<QVector<QPoint>> UnitedRectangles::pasteTogether (QVector<QVector<Intersection>> & intersections, const int count)
{
	QVector<QVector<QPoint>> figures;

	for (int i = 0; i < count; i++)
	{
		int size = intersections.at(i).count();
		for (int j = 0; j < size; j++)
		{
			if (intersections.at(i).at(j).sign == true)
			{
				// ������� ��������������
			}
		}
	}

	return figures;
}

void UnitedRectangles::writeResult (QVector<QVector<QPoint>> & figures)
{
	QFile File ("result.txt");	// ��������� ���� � ��� �����
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))	// ������� ���� ��� ������
	{
		QTextStream Out(&File);	// ������� �����

		int first = 0;	// ����� �������� �������
		int second = 0;	// ����� ����������� �������

		first = figures.count();	// �������� ����� �������� �������

		for (int i = 0; i < first; i++)	// ��� ������� �������� �������� �������
		{
			second = figures.at(i).count();	// �������� ����� ����������� �������
			for (int j = 0; j < second; j++)	// ��� ������� �������� ����������� �������...
			{
				Out << figures.at(i).at(j);	// �������� ����� � �����
				Out << " ";
			}
			Out << "\r\n" << "\r\n";
		}
		File.close();	// ������� ����
	}
}

UnitedRectangles::~UnitedRectangles(void)
{
}
