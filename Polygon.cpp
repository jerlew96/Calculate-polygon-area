#include <iostream>
#include <vector>
#include <string>
#include "Polygon.h"

bool Point::isFloat(const std::string& str)
{
	int numOfDot = 0;
	for (std::string::size_type i = 0; i != str.length(); ++i)
	{

		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else if (str[i] == '.')
		{
			numOfDot++;
			if (numOfDot > 1)
			{
				return false;
			}
		}
		else
			return false;
	}
	return true;
}

std::vector<Point> input()
{
	float x = 0, y = 0;
	std::vector<Point> vectorIn;
	vectorIn.clear();
	int i = 0;
	std::string s;
	while (1)
	{
		i++;
		std::cout << "�������" << i << "���ĵ��x ������a����" << std::endl;
		std::cin >> s;
		Point point;
		bool isfloat = point.isFloat(s);
		if (!isfloat) {
			break;
		}
		else {

			x = atof(s.c_str());
			std::cout << "�������" << i << "���ĵ��y" << std::endl;
			std::cin >> y;

			Point point(x, y);
			vectorIn.push_back(point);
			continue;

		}

	}
	for (std::vector<Point>::iterator it = vectorIn.begin(); it != vectorIn.end(); it++) {
		std::cout << (*it).xx << "," << (*it).yy << std::endl;
	}
	return vectorIn;
}

void calculate(std::vector<Point> vecPos)
{

	Point p1;
	Point p2;


	float sum = 0, sum1 = 0, sum2 = 0;

	for (std::vector<Point>::size_type i = 0; i < vecPos.size(); i++) {
		p1 = vecPos[i];
		p2 = vecPos[(i + 1) % vecPos.size()];
		sum1 = p1.xx * p2.yy + sum1;
		sum2 = p1.yy * p2.xx + sum2;
	}
	sum = (sum1 - sum2) / 2;
	std::cout << "������������Ϊ" << sum << std::endl;
}