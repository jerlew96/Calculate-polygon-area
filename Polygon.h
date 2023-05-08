#pragma once
#include <iostream>
#include <vector>
#include <string>

class Point 
{
	friend void calculate(std::vector<Point> vecPos);
	friend std::vector<Point> input();

public:
	Point() = default;
	Point(float x, float y): xx(x), yy(y){}
	bool isFloat(const std::string &str);

private:
	float xx;
	float yy;

};

std::vector<Point> input();

void calculate(std::vector<Point> vecPos);