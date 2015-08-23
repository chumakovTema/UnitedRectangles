//!
//! \file UnitedRectangles.cpp
//!
#include "UnitedRectangles.h"

/*!
* \fn UnitedRectangles::UnitedRectangles(void)
* ����������� �� ���������
*/
UnitedRectangles::UnitedRectangles(void)
{
}

/*!
* \fn UnitedRectangles::~UnitedRectangles(void)
* ���������� �� ���������
*/
UnitedRectangles::~UnitedRectangles(void)
{
}

/*!
* \fn QTextStream & operator >> (QTextStream & in, Rectangle & other)
* ������������� �������� ������ �� ���������� ������
* \param [in, out] in - ������ �� �����
* \param [in, out] other - ������ �� ������, ������� �������� �� ������
* \return ������ �� �����
*/
QTextStream & operator >> (QTextStream & in, Rectangle & other)
{
	in >> other.x >> other.y >> other.length >> other.width;
	return in;
}

/*!
* \fn QTextStream & operator << (QTextStream & out, const QPoint & other)
* ������������� �������� ������ � ��������� �����
* \param [in, out] out - ������ �� �����
* \param [in, out] other - ������ �� ������, ������� ������������ � �����
* \return ������ �� �����
*/
QTextStream & operator << (QTextStream & out, const QPoint & other)
{
	out << "(" << other.x() << other.y() << ")";
	return out;
}

/*!
* \fn QVector<QPoint> UnitedRectangles::getTops (Rectangle it)
* ��������� ��������� ���� ������ ��������������
* \param [in] it - �������������, ��� �������� ���� �������
* \return ������ ������
*/
QVector<QPoint> UnitedRectangles::getTops (Rectangle it)
{
	// �������� ������� ������� ��������������
	QVector <QPoint> tops;
	QPoint first, second, third, fourth;

	first = QPoint (it.x, it.y);
	second = QPoint (it.x + it.length, it.y);
	third = QPoint (it.x, it.y + it.width);
	fourth = QPoint (it.x + it.length, it.y + it.width);

	tops << first << second << third << fourth;
	return tops;
}

/*!
* \fn QVector <Rectangle> UnitedRectangles::readData ()
* ������ ������ �� �����
* \return ������ ���������������
*/
QVector <Rectangle> UnitedRectangles::readData ()
{
	QVector <Rectangle> data;	/**< QVector <Rectangle> data - ��������� ������ */
	QTextStream out (stdout);
	int count = 0;

	QFile file ("target.txt");			// ������� ���� � ��� ������
	if (file.open(QIODevice::ReadOnly))	// ���� ������� �������, ��...
	{
		QTextStream In (&file);		// ������� �������� �����
		In >> count;				// ������� ���������� ���������������
		if (count == 0)
		{
			out << "������! � ����� ��� ���������������, ��� �� ���������� �� �������!" << flush;
			return data;
		}

		for (int i = 0; i < count; i++)	// ������� ������ �������������
		{
			Rectangle temp;		// ��������� �������������
			In >> temp;			// ������ ��� �� �����
			data.append(temp);	// �������� ������������� � ������
		}
		file.close();			// ������� ����
	}

	return data;
}

/*!
* \fn int UnitedRectangles::correctInput (QVector <Rectangle> & rectangles)
* �������� ������������ ������� ������
* \param [in] rectangles - ������ �� ������ ���������������
* \return ��� ������
*/
int UnitedRectangles::correctInput (QVector <Rectangle> & rectangles)
{
	int count = rectangles.count();
	int err = 0;
	QTextStream out (stdout);

	for (int i = 0; i < count; i++)
	{
		if (rectangles[i].x > 10000 || rectangles[i].x < -10000)
		{
			out << "������! ����������-�������� ������� ����� �������������� " << i << " ����� " << rectangles[i].x << flush;
			out << "���������� �������� ���������: [-10000; 10000]" << flush;
			err = 1;
		}
		if (rectangles[i].y > 10000 || rectangles[i].y < -10000)
		{
			out << "������! ����������-�������� ������� ����� �������������� " << i << " ����� " << rectangles[i].y << flush;
			out << "���������� �������� ���������: [-10000; 10000]" << flush;
			err = 2;
		}
		if (rectangles[i].length > 10000)
		{
			out << "������! ����� �������������� " << i << " ������ 10000" << flush;
			err = 3;
		}
		if (rectangles[i].width > 10000)
		{
			out << "������! ������ �������������� " << i << " ������ 10000" << flush;
			err = 4;
		}
	}

	return err;
}

/*!
* \fn int UnitedRectangles::correctOutput (Rectangle & figure)
* �������� ������������ �������� ������
* \param [in] figure - ������ �� ����� �������������
* \return ��� ������
*/
int UnitedRectangles::correctOutput (QVector<Rectangle> & figure)
{
	QTextStream out (stdout);
	int err = 0;

	for (int i = 0; i < figure.count(); i++)
	{
		if (figure[i].x > 10000 || figure[i].x < -10000)
		{
			out << "������! ����������-�������� ������� ����� ������ �������������� " << i << " ����� " << figure[i].x << flush;
			out << "���������� �������� ���������: [-10000; 10000]" << flush;
			out << "��������� � ������������ �������� ������� ������" << flush;
			err = 1;
		}
		if (figure[i].y > 10000 || figure[i].y < -10000)
		{
			out << "������! ����������-�������� ������� ����� ������ �������������� " << i << " ����� " << figure[i].y << flush;
			out << "���������� �������� ���������: [-10000; 10000]" << flush;
			out << "��������� � ������������ �������� ������� ������" << flush;
			err = 2;
		}
		if (figure[i].length > 10000)
		{
			out << "������! ����� ������ �������������� " << i << " ������ 10000" << flush;
			err = 3;
		}
		if (figure[i].width > 10000)
		{
			out << "������! ������ ������ �������������� " << i << " ������ 10000" << flush;
			err = 4;
		}
	}

	return err;
}

/*!
* \fn bool compareIndexes (QVector<int> & line)
* ����������� ����������� ����� � �������
* \param [in] line - ������ �� ������� ��������� �����
* \param [in] num - ������ �������� ��������������
* \return ������� ����������� � ��������� �������� �������
*/
bool compareIndexes (QVector<int> & line, int num)
{
	bool index = false;
	for (int k = 0; k < line.count() && index != true; k++)	// ���������, ��� � ��������� ��� ��� �������, ������� j
	{
		if (line[k] != num)
		{
			index = false;
		}
		else
		{
			index = true;
		}
	}
	return index;
}

/*!
* \fn bool searchInOtherLines (QVector<QVector<int>> & map, int num)
* ����������� ����������� ����� � �����
* \param [in] map - ������ �� �����
* \param [in] num - ������ �������� ��������������
* \return ������� ����������� � ����� �������� �������
*/
bool searchInOtherLines (QVector<QVector<int>> & map, int num)
{
	bool index = false;
	for (int i = 0; i < map.count() && index != true; i++)
	{
		for (int j = 0; j < map[i].count() && index != true; j++)
		{
			if (map[i][j] != num)
			{
				index = false;
			}
			else
			{
				index = true;
			}
		}
	}
	return index;
}

/*!
* \fn QVector<QVector<Intersection>> UnitedRectangles::hasIntersectionWithAhother (QVector <Rectangle> & rectangles)
* ����������� ����� ����������� ���������������
* \param [in] rectangles - ������ ���������������
* \return ����� ����������� ���������������
*/
QVector<QVector<int>> UnitedRectangles::hasIntersectionWithAhother (QVector <Rectangle> & rectangles)
{
	QVector<QVector<int>> map;	// ����� �����������
	QVector<int> line;			// ��������� � �����
	int count = rectangles.count();	// ���������� ���������������
	bool isIndex = false;	// ������� ����������� ����� � �������
	bool inMap = false;		// ������� ����������� ����� � �����

	line.clear();
	for (int i = 0; i < count; i++)	// ��� ������� ��������������...
	{
		inMap = searchInOtherLines (map, i);	// ���������, ��� � ����� ��� i-�� ��������������
		if (inMap == false)	// ���� ��� ���, ��...
		{
			line.append(i);	// ������ ����� ��������� � ����� i
		}

		if (line.count() > 0)
		{
			for (int j = 0; j < count; j++)	// ��� ������� ��������������...
			{
				if (i != j)	// ���� ������� ������������ ��������������� �� �����...
				{
					if (rectangles[j].x >= rectangles[i].x && rectangles[j].y >= rectangles[i].y)	// ���� j-�� ������������� � ������� i-��...
					{
						if (rectangles[i].x + rectangles[i].length >= rectangles[j].x && rectangles[i].y + rectangles[i].width >= rectangles[j].y)	// ���� j-�� ������ i-��
						{
							isIndex = compareIndexes(line, j);
							if (isIndex == false)
							{
								line.append(j);
							}
						}
					}
					else if (rectangles[j].x < rectangles[i].x || rectangles[j].y < rectangles[i].y)	// ���� j-�� ������������� ��� c������ i-��...
					{
						if (rectangles[j].y >= rectangles[i].y)	// ���� j-�� ������������� � c������ ����� i-��...
						{
							if (rectangles[j].x + rectangles[j].length >= rectangles[i].x && rectangles[j].y <= rectangles[i].y + rectangles[i].width)
							{
								isIndex = compareIndexes(line, j);
								if (isIndex == false)
								{
									line.append(j);
								}
							}
						}
						else if (rectangles[j].x >= rectangles[i].x)	// ���� j-�� ������������� � c������ ����� i-��...
						{
							if (rectangles[j].y + rectangles[j].width >= rectangles[i].y && rectangles[j].x <= rectangles[i].x + rectangles[i].length)
							{
								isIndex = compareIndexes(line, j);
								if (isIndex == false)
								{
									line.append(j);
								}
							}
						}
						else	// ���� j-�� ������������� � ������� �����-����� i-��...
						{
							if (rectangles[j].y + rectangles[j].width >= rectangles[i].y && rectangles[j].x + rectangles[j].length >= rectangles[i].x)
							{
								isIndex = compareIndexes(line, j);
								if (isIndex == false)
								{
									line.append(j);
								}
							}
						}
					}
				}
			}
		map.append(line);
		line.clear();
		}
	}

	return map;
}

/*!
* \fn void UnitedRectangles::rebuildMap (QVector<QVector<int>> & map)
* ���������� �����, ���� � � ��������� ���� ������������� ��������
* \param [in, out] map - ������ �� �����
*/
void UnitedRectangles::rebuildMap (QVector<QVector<int>> & map)
{
	for (int i = 0; i < map.count(); i++)	// ����� �������
	{
		for (int j = 0; j < map[i].count(); j++)
		{
			for (int k = i + 1; k < map.count(); k++)	// ����� �������, � ������� ���������� ������
			{
				for (int l = 0; l < map[k].count(); l++)
				{
					if (map[i][j] == map[k][l])	// ���� ��� �����, ��...
					{
						for (int m = 0; m < map[k].count(); m++)
						{
							if (map[i][j] != map[k][m])
							{
								map[i].append(map[k][m]);	// ���������� ��� �������, ����� ������������� � ������ ���������...
							}
						}
						map.remove(k);	// � ������ �������
						i = 0;	// ������ � ������ �����
						j = 0;
					}
				}
			}
		}
	}
}

/*!
* \fn QVector<Rectangle> UnitedRectangles::pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap)
* ������� ��������������� � �����
* \param [in] figure - ������ �� ������ �������� ���������������
* \param [in] newMap - ������ �� ���������������� ����� �����������
* \return ������ ����� ���������������
*/
QVector<Rectangle> UnitedRectangles::pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap)
{
	QVector<Rectangle> newRectangles;
	QVector <QPoint> points;	// ������ ������ ������ ��������������
	QPoint A, B, C, D;			// ��������� �����, �������������� ����� �������������

	for (int i = 0; i < newMap.count(); i++)	// ��� ������ ������ �� �����...
	{
		Rectangle temp;

		A = QPoint(figure[newMap[i][0]].x, figure[newMap[i][0]].y);
		B = QPoint(figure[newMap[i][0]].x + figure[newMap[i][0]].length, figure[newMap[i][0]].y);
		C = QPoint(figure[newMap[i][0]].x, figure[newMap[i][0]].y + figure[newMap[i][0]].width);
		D = QPoint(figure[newMap[i][0]].x + figure[newMap[i][0]].length, figure[newMap[i][0]].y + figure[newMap[i][0]].width);
		for (int j = 1; j < newMap[i].count(); j++)	// ��������� ������������� � ������������ � ������...
		{
			if (figure[newMap[i][j]].x < A.x())
			{
				A.setX(figure[newMap[i][j]].x);
				if (figure[newMap[i][j]].y < C.y())
				{
					A.setY(figure[newMap[i][j]].y);
				}
			}
			if (figure[newMap[i][j]].x + figure[newMap[i][j]].length > A.x())
			{
				B.setX(figure[newMap[i][j]].x + figure[newMap[i][j]].length);
				if (figure[newMap[i][j]].y < B.y())
				{
					B.setY(figure[newMap[i][j]].y);
				}
			}
			if (figure[newMap[i][j]].x < D.x())
			{
				C.setX(figure[newMap[i][j]].x);
				if (figure[newMap[i][j]].y + figure[newMap[i][j]].width > C.y())
				{
					C.setY(figure[newMap[i][j]].y + figure[newMap[i][j]].width);
				}
			}
			if (figure[newMap[i][j]].x + figure[newMap[i][j]].length > D.x())
			{
				D.setX(figure[newMap[i][j]].x + figure[newMap[i][j]].length);
				if (figure[newMap[i][j]].y + figure[newMap[i][j]].width > B.y())
				{
					D.setY(figure[newMap[i][j]].y + figure[newMap[i][j]].width);
				}
			}
		}

		points << A << B << C << D;	// �������� ���������� ������� � ������
		int Xmin = figure[newMap[i][0]].x;
		int Ymin = figure[newMap[i][0]].y;
		int Xmax = figure[newMap[i][0]].x;
		int Ymax = figure[newMap[i][0]].y;
		for (int i = 0; i < 4; i++)
		{	// ��������� ������� ��������������
			if (points[i].x() < Xmin)
			{
				Xmin = points[i].x();
			}
			if (points[i].y() < Ymin)
			{
				Ymin = points[i].y();
			}
			if (points[i].x() > Xmax)
			{
				Xmax = points[i].x();
			}
			if (points[i].y() > Ymax)
			{
				Ymax = points[i].y();
			}
		}

		temp.x = Xmin;
		temp.y = Ymin;
		temp.length = Xmax - Xmin;
		temp.width = Ymax - Ymin;

		newRectangles.append(temp);
		points.clear();
	}

	return newRectangles;
}

/*!
* \fn void writeResult (QVector<Rectangle>  & newFigures)
* ������ ���������� ��������������� � ����
* \param [in] newFigures - ������ �� ������ ����� ���������������
*/
void UnitedRectangles::writeResult (QVector<Rectangle>  & newFigures)
{
	QFile File("result.txt");	// Bindind file to name of file
	
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))	// Opening file for reading
	{
		QTextStream Out (&File);

		for (int i = 0; i < newFigures.count(); i++)
		{
			Out << newFigures[i].x << " " << newFigures[i].y << " " << newFigures[i].length << " " << newFigures[i].width << "\r\n";
		}

		File.close();
	}
}