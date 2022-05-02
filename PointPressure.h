#pragma once
class PointPressure
{
public:
	PointPressure(double r, double P);
	const double k = 1;
	const double ratio = 1;
	double x, r, y, P;
	void setX(double r);
	void setY(double P);
};

