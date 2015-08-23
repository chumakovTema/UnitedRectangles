//!
//! \file UnitedRectangles.cpp
//!
#include "UnitedRectangles.h"

/*!
* \fn UnitedRectangles::UnitedRectangles(void)
* Конструктор по умолчанию
*/
UnitedRectangles::UnitedRectangles(void)
{
}

/*!
* \fn UnitedRectangles::~UnitedRectangles(void)
* Деструктор по умолчанию
*/
UnitedRectangles::~UnitedRectangles(void)
{
}

/*!
* \fn QTextStream & operator >> (QTextStream & in, Rectangle & other)
* Перегруженная операция чтения из текстового потока
* \param [in, out] in - ссылка на поток
* \param [in, out] other - ссылка на объект, который читается из потока
* \return ссылка на поток
*/
QTextStream & operator >> (QTextStream & in, Rectangle & other)
{
	in >> other.x >> other.y >> other.length >> other.width;
	return in;
}

/*!
* \fn QTextStream & operator << (QTextStream & out, const QPoint & other)
* Перегруженная операция записи в текстовый поток
* \param [in, out] out - ссылка на поток
* \param [in, out] other - ссылка на объект, который записывается в поток
* \return ссылка на поток
*/
QTextStream & operator << (QTextStream & out, const QPoint & other)
{
	out << "(" << other.x() << other.y() << ")";
	return out;
}

/*!
* \fn QVector<QPoint> UnitedRectangles::getTops (Rectangle it)
* Получение координат всех вершин прямоугольника
* \param [in] it - прямоугольник, для которого ищем вершины
* \return вектор вершин
*/
QVector<QPoint> UnitedRectangles::getTops (Rectangle it)
{
	// Получить вершины первого прямоугольника
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
* Чтение данных из файла
* \return вектор прямоугольников
*/
QVector <Rectangle> UnitedRectangles::readData ()
{
	QVector <Rectangle> data;	/**< QVector <Rectangle> data - Считанные денные */
	QTextStream out (stdout);
	int count = 0;

	QFile file ("target.txt");			// Связать файл с его именем
	if (file.open(QIODevice::ReadOnly))	// Если удалось открыть, то...
	{
		QTextStream In (&file);		// Создать файловый поток
		In >> count;				// Считать количество прямоугольников
		if (count == 0)
		{
			out << "Ошибка! В файле нет прямоугольников, или их количество не указано!" << flush;
			return data;
		}

		for (int i = 0; i < count; i++)	// Считать каждый прямоугольник
		{
			Rectangle temp;		// Временный прямоугольник
			In >> temp;			// Читаем его из файла
			data.append(temp);	// Добавить прямоугольник в вектор
		}
		file.close();			// Закрыть файл
	}

	return data;
}

/*!
* \fn int UnitedRectangles::correctInput (QVector <Rectangle> & rectangles)
* Проверка корректности входных данных
* \param [in] rectangles - ссылка на вектор прямоугольников
* \return код ошибки
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
			out << "Ошибка! Координата-абсцисса базовой точки прямоугольника " << i << " равна " << rectangles[i].x << flush;
			out << "Допустимый диапазон координат: [-10000; 10000]" << flush;
			err = 1;
		}
		if (rectangles[i].y > 10000 || rectangles[i].y < -10000)
		{
			out << "Ошибка! Координата-ордината базовой точки прямоугольника " << i << " равна " << rectangles[i].y << flush;
			out << "Допустимый диапазон координат: [-10000; 10000]" << flush;
			err = 2;
		}
		if (rectangles[i].length > 10000)
		{
			out << "Ошибка! Длина прямоугольника " << i << " больше 10000" << flush;
			err = 3;
		}
		if (rectangles[i].width > 10000)
		{
			out << "Ошибка! Ширина прямоугольника " << i << " больше 10000" << flush;
			err = 4;
		}
	}

	return err;
}

/*!
* \fn int UnitedRectangles::correctOutput (Rectangle & figure)
* Проверка корректности выходных данных
* \param [in] figure - ссылка на новый прямоугольник
* \return код ошибки
*/
int UnitedRectangles::correctOutput (QVector<Rectangle> & figure)
{
	QTextStream out (stdout);
	int err = 0;

	for (int i = 0; i < figure.count(); i++)
	{
		if (figure[i].x > 10000 || figure[i].x < -10000)
		{
			out << "Ошибка! Координата-абсцисса базовой точки нового прямоугольника " << i << " равна " << figure[i].x << flush;
			out << "Допустимый диапазон координат: [-10000; 10000]" << flush;
			out << "Убедитесь в правильности введённых входных данных" << flush;
			err = 1;
		}
		if (figure[i].y > 10000 || figure[i].y < -10000)
		{
			out << "Ошибка! Координата-ордината базовой точки нового прямоугольника " << i << " равна " << figure[i].y << flush;
			out << "Допустимый диапазон координат: [-10000; 10000]" << flush;
			out << "Убедитесь в правильности введённых входных данных" << flush;
			err = 2;
		}
		if (figure[i].length > 10000)
		{
			out << "Ошибка! Длина нового прямоугольника " << i << " больше 10000" << flush;
			err = 3;
		}
		if (figure[i].width > 10000)
		{
			out << "Ошибка! Ширина нового прямоугольника " << i << " больше 10000" << flush;
			err = 4;
		}
	}

	return err;
}

/*!
* \fn bool compareIndexes (QVector<int> & line)
* Определение присутствия числа в векторе
* \param [in] line - ссылка на текущую параллель карты
* \param [in] num - индекс искомого прямоугольника
* \return признак присутствия в параллели искомого индекса
*/
bool compareIndexes (QVector<int> & line, int num)
{
	bool index = false;
	for (int k = 0; k < line.count() && index != true; k++)	// Проверить, что в параллели ещё нет индекса, равного j
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
* Определение присутствия числа в карте
* \param [in] map - ссылка на карту
* \param [in] num - индекс искомого прямоугольника
* \return признак присутствия в карте искомого индекса
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
* Составление карты пересечений прямоугольников
* \param [in] rectangles - список прямоугольников
* \return карта пересечений прямоугольников
*/
QVector<QVector<int>> UnitedRectangles::hasIntersectionWithAhother (QVector <Rectangle> & rectangles)
{
	QVector<QVector<int>> map;	// Карта пересечений
	QVector<int> line;			// Параллель в карте
	int count = rectangles.count();	// Количество прямоугольников
	bool isIndex = false;	// Признак присутствия числа в векторе
	bool inMap = false;		// Признак присутствия числа в карте

	line.clear();
	for (int i = 0; i < count; i++)	// Для каждого прямоугольника...
	{
		inMap = searchInOtherLines (map, i);	// Проверить, что в карте нет i-го прямоугольника
		if (inMap == false)	// Если его нет, то...
		{
			line.append(i);	// Начать новую параллель с числа i
		}

		if (line.count() > 0)
		{
			for (int j = 0; j < count; j++)	// Для каждого прямоугольника...
			{
				if (i != j)	// Если индексы определяемых прямоугольников не равны...
				{
					if (rectangles[j].x >= rectangles[i].x && rectangles[j].y >= rectangles[i].y)	// Если j-ый прямоугольник в секторе i-го...
					{
						if (rectangles[i].x + rectangles[i].length >= rectangles[j].x && rectangles[i].y + rectangles[i].width >= rectangles[j].y)	// Если j-ый внутри i-го
						{
							isIndex = compareIndexes(line, j);
							if (isIndex == false)
							{
								line.append(j);
							}
						}
					}
					else if (rectangles[j].x < rectangles[i].x || rectangles[j].y < rectangles[i].y)	// Если j-ый прямоугольник вне cектора i-го...
					{
						if (rectangles[j].y >= rectangles[i].y)	// Если j-ый прямоугольник в cекторе слева i-го...
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
						else if (rectangles[j].x >= rectangles[i].x)	// Если j-ый прямоугольник в cекторе снизу i-го...
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
						else	// Если j-ый прямоугольник в секторе слева-снизу i-го...
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
* Пересборка карты, если в её паралелях есть повторяющиеся элементы
* \param [in, out] map - ссылка на карту
*/
void UnitedRectangles::rebuildMap (QVector<QVector<int>> & map)
{
	for (int i = 0; i < map.count(); i++)	// Взять элемент
	{
		for (int j = 0; j < map[i].count(); j++)
		{
			for (int k = i + 1; k < map.count(); k++)	// Взять элемент, с которым сравнивать первый
			{
				for (int l = 0; l < map[k].count(); l++)
				{
					if (map[i][j] == map[k][l])	// Если они равны, то...
					{
						for (int m = 0; m < map[k].count(); m++)
						{
							if (map[i][j] != map[k][m])
							{
								map[i].append(map[k][m]);	// Переписать все индексы, кроме сравниваемого в первую параллель...
							}
						}
						map.remove(k);	// А вторую стереть
						i = 0;	// Начать с начала карты
						j = 0;
					}
				}
			}
		}
	}
}

/*!
* \fn QVector<Rectangle> UnitedRectangles::pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap)
* Склейка прямоугольников в новые
* \param [in] figure - ссылка на вектор исходных прямоугольников
* \param [in] newMap - ссылка на конвертированную карту пересечений
* \return вектор новых прямоугольников
*/
QVector<Rectangle> UnitedRectangles::pasteTogether (QVector<Rectangle> & figure, QVector<QVector<int>> & newMap)
{
	QVector<Rectangle> newRectangles;
	QVector <QPoint> points;	// Вектор вершин нового прямоугольника
	QPoint A, B, C, D;			// Временные точки, ограничивающие новый прямоугольник

	for (int i = 0; i < newMap.count(); i++)	// Для каждой строки из карты...
	{
		Rectangle temp;

		A = QPoint(figure[newMap[i][0]].x, figure[newMap[i][0]].y);
		B = QPoint(figure[newMap[i][0]].x + figure[newMap[i][0]].length, figure[newMap[i][0]].y);
		C = QPoint(figure[newMap[i][0]].x, figure[newMap[i][0]].y + figure[newMap[i][0]].width);
		D = QPoint(figure[newMap[i][0]].x + figure[newMap[i][0]].length, figure[newMap[i][0]].y + figure[newMap[i][0]].width);
		for (int j = 1; j < newMap[i].count(); j++)	// Расширить прямоугольник в соответствии с картой...
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

		points << A << B << C << D;	// Записать полученные вершины в вектор
		int Xmin = figure[newMap[i][0]].x;
		int Ymin = figure[newMap[i][0]].y;
		int Xmax = figure[newMap[i][0]].x;
		int Ymax = figure[newMap[i][0]].y;
		for (int i = 0; i < 4; i++)
		{	// Выровнять стороны прямоугольника
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
* Запись полученных прямоугольников в файл
* \param [in] newFigures - ссылка на вектор новых прямоугольников
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