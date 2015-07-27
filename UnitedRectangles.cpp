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

	first = QPoint::QPoint (it.x, it.y);
	second = QPoint::QPoint (it.x + it.length, it.y);
	third = QPoint::QPoint (it.x, it.y + it.width);
	fourth = QPoint::QPoint (it.x + it.length, it.y + it.width);

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
	int count = 0;

	QFile file ("target.txt");			// Связать файл с его именем
	if (file.open(QIODevice::ReadOnly))	// Если удалось открыть, то...
	{
		QTextStream In (&file);		// Создать файловый поток
		In >> count;				// Считать количество прямоугольников

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

//!
//! SPLICE_RECTANGLES_EASY_VERSION - макрос, открывающий или закрывающий доступ к облегчённому варианту решения
//!
#ifdef SPLICE_RECTANGLES_EASY_VERSION
/*!
* \fn Rectangle UnitedRectangles::pasteAllTogetherEasy (QVector<Rectangle> & rectangles)
* Объединение всех прямоугольников в один новый
* \param [in] rectangles - ссылка на вектор прямоугольников
* \return новый прямоугольников
*/
Rectangle UnitedRectangles::pasteAllTogetherEasy (QVector<Rectangle> & rectangles)
{
	Rectangle result;	/**< Rectangle result - полученный новый прямоугольник */

	QVector <QPoint> points;	// Вектор вершин нового прямоугольника
	QPoint A = QPoint::QPoint(rectangles.at(0).x, rectangles.at(0).y);	// Левая нижняя вершина
	QPoint B = QPoint::QPoint(rectangles.at(0).x + rectangles.at(0).length, rectangles.at(0).y);// Правая нижняя вершина
	QPoint C = QPoint::QPoint(rectangles.at(0).x, rectangles.at(0).y + rectangles.at(0).width);	// Левая верхняя вершина
	QPoint D = QPoint::QPoint(rectangles.at(0).x + rectangles.at(0).length, rectangles.at(0).y + rectangles.at(0).width);	// Правая верхняя вершина

	for (int i = 0; i < rectangles.count(); i++)	// Рассматривая каждый прямоугольник...
	{	// Определить, где будут вершины нового прямоугольника
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

	points << A << B << C << D;	// Записать полученные вершины в вектор
	int Xmin = 0;
	int Ymin = 0;
	int Xmax = 0;
	int Ymax = 0;
	for (int i = 0; i < 4; i++)
	{	// Выровнять стороны прямоугольника
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

/*!
* \fn void UnitedRectangles::writeResultEasy (Rectangle & figure)
* Запись результата в файл при облегчённом решении
* \param [in] figure - ссылка на прямоугольник
*/
void UnitedRectangles::writeResultEasy (Rectangle & figure)
{
	QFile File ("result.txt");	// Привязать файл к его имени
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))	// Открыть файл для записи
	{
		QTextStream Out(&File);	// Создать поток
		Out << figure.x << " " << figure.y << " " << figure.length << " " << figure.width;
		File.close();			// Закрыть файл
	}
}
#else
/*!
* \fn QVector<QVector<QPoint>> UnitedRectangles::pasteAllTogether (QVector<Rectangle> & rectangles)
* Объединение всех прямоугольников в одну новую фигуру
* \param [in] rectangles - ссылка на вектор прямоугольников
* \return вектор полученных фигур
*/
QVector<QVector<QPoint>> UnitedRectangles::pasteAllTogether (QVector<Rectangle> & rectangles)
{
	QVector<QVector<QPoint>> figures;	/**< QVector<QVector<QPoint>> figures - Вектор фигур, результат */

	int count = rectangles.count();	// Получить количество прямоугольников
	QVector<QVector<Intersection>> intersections;	/**< QVector<QVector<Intersection>> intersections - Карта пересечений прямоугольников */

	for (int i = 0; i < count; i++)	// Для каждого прямоугольника...
	{
		for (int j = 0; j < count; j++)	// Кроме текущего взятого...
		{
			if (i != j)	// Если номер первого не совпадает с номером второго...
			{
				intersections = hasIntersectionWithAhother (rectangles.at(i), i, rectangles.at(j), j);// Найти пересечение
			}
		}

		figures = pasteTogether (intersections, count);	// Склеить многоугольники // А ЗДЕСЬ ЛИ ЭТО ДЕЙСТВИЕ???
	}

	return figures;
}

/*!
* \fn QVector<QVector<Intersection>> UnitedRectangles::hasIntersectionWithAhother (Rectangle first, int current, Rectangle other, int second)
* Составление карты пересечений прямоугольников
* \param [in] first - первый прямоугольник
* \param [in] current - его индекс в списке прямоугольников
* \param [in] other - второй прямоугольник
* \param [in] second - его индекс в списке прямоугольников
* \return карта пересечений прямоугольников
*/
QVector<QVector<Intersection>> UnitedRectangles::hasIntersectionWithAhother (Rectangle first, int current, Rectangle other, int second)
{
	QVector<QVector<Intersection>> map;	/**< QVector<QVector<Intersection>> map - Карта пересечений */
	QVector<Intersection> line;		// Строка в карте

	QVector <QPoint> firstRec;
	QVector <QPoint> secondRec;
	firstRec = getTops (first);		// Получить вершины первого прямоугольника
	secondRec = getTops (other);	// Получить вершины второго прямоугольника

	// Проверка пересечения
	if ((secondRec[0].x() > firstRec[0].x() && secondRec[0].y() > firstRec[0].y()) && (secondRec[3].x() < firstRec[3].x() && secondRec[3].y() < firstRec[3].y())) // Второй внутри первого
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = false;
		temp.intersection.clear();

		line << temp;
		map << line;
	}
	else if (secondRec[0].x() > firstRec[1].x() || secondRec[0].y() > firstRec[3].y() || secondRec[3].x() < firstRec[0].x() || secondRec[3].y() < firstRec[0].y())	// Второй вне первого
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = false;
		temp.intersection.clear();

		line << temp;
		map << line;
	}
	else if (secondRec[0] == firstRec[0] && other.length < first.length && other.width < first.width) // Левые нижние углы соприкасаются
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec[0].x(), firstRec[0].y()) << QPoint::QPoint(secondRec[1].x(), firstRec[0].y()) << QPoint::QPoint(firstRec[0].x(), secondRec[2].y());

		line << temp;
		map << line;
	}
	else if (secondRec[1] == firstRec[1] && other.length < first.length && other.width < first.width) // Правые нижние углы соприкасаются
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(secondRec[0].x(), firstRec[1].y()) << QPoint::QPoint(firstRec[1].x(), firstRec[1].y()) << QPoint::QPoint(firstRec[1].x(), secondRec[3].y());

		line << temp;
		map << line;
	}
	else if (secondRec[2] == firstRec[2] && other.length < first.length && other.width < first.width) // Левые верхние углы соприкасаются
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec[2].x(), secondRec[0].y()) << QPoint::QPoint(firstRec[2].x(), firstRec[2].y()) << QPoint::QPoint(secondRec[3].x(), firstRec[2].y());

		line << temp;
		map << line;
	}
	else if (secondRec[3] == firstRec[3] && other.length < first.length && other.width < first.width) // Правые верхние углы соприкасаются
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec[3].x(), secondRec[1].y()) << QPoint::QPoint(secondRec[2].x(), firstRec[3].y()) << QPoint::QPoint(firstRec[3].x(), firstRec[3].y());

		line << temp;
		map << line;
	}
	else if (secondRec[0].x() == firstRec[0].x() && secondRec[0].y() > firstRec[0].y() && other.length == first.length && other.width < (first.width - (secondRec[0].y() - firstRec[0].y()) - (firstRec[3].y() - secondRec[3].y()))) // Правые верхние углы соприкасаются
	{
		Intersection temp;
		temp.baseIndex = current;
		temp.secondIndex = second;
		temp.sign = true;
		temp.intersection << QPoint::QPoint(firstRec[3].x(), secondRec[1].y()) << QPoint::QPoint(secondRec[2].x(), firstRec[3].y()) << QPoint::QPoint(firstRec[3].x(), firstRec[3].y());

		line << temp;
		map << line;
	}

	return map;
}

/*!
* \fn QVector<QVector<QPoint>> UnitedRectangles::pasteTogether (QVector<QVector<Intersection>> & intersections, const int count)
* Склейка двух прямоугольников
* \param [in] intersections - ссылка на карту пересечений
* \param [in] count - количество прямоугольников
* \return вектор фигур
*/
QVector<QVector<QPoint>> UnitedRectangles::pasteTogether (QVector<QVector<Intersection>> & intersections, const int count)
{
	QVector<QVector<QPoint>> figures;	/**< QVector<QVector<QPoint>> figures - Вектор фигур, результат */

	for (int i = 0; i < count; i++)		// Для каждого прямоугольника
	{
		int size = intersections[i].count();// Получить длину строки карты
		for (int j = 0; j < size; j++)		// Для каждого элемента карты...
		{
			if (intersections[i][j].sign == true)	// Если прямоугольники пересекаются или соприкасаются...
			{
				// Склеить их
			}
		}
	}

	return figures;
}

/*!
* \fn void UnitedRectangles::writeResult (QVector<QVector<QPoint>> & figures)
* Запись полученных фигур в файл
* \param [in] figures - ссылка на вектор полученных фигур
*/
void UnitedRectangles::writeResult (QVector<QVector<QPoint>> & figures)
{
	QFile File ("result.txt");	// Привязать файл к его имени
	if (File.open(QIODevice::WriteOnly | QIODevice::Truncate))	// Открыть файл для записи
	{
		QTextStream Out(&File);	// Создать поток

		int first = 0;	// Длина внешнего вектора
		int second = 0;	// Длина внутреннего вектора

		first = figures.count();	// Получить длину внешнего вектора

		for (int i = 0; i < first; i++)	// Для каждого элемента внешнего вектора
		{
			second = figures.at(i).count();	// Получить длину внутреннего вектора
			for (int j = 0; j < second; j++)// Для каждого элемента внутреннего вектора...
			{
				Out << figures[i][j];	// Записать точку в поток
				Out << " ";
			}
			Out << "\r\n" << "\r\n";
		}
		File.close();	// Закрыть файл
	}
}

#endif