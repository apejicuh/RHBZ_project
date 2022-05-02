#include "PointPressure.h"

PointPressure::PointPressure(double r, double P) {
	this->r = r;
	this->P = P;
	setX(r);
	setY(P);
}

void PointPressure::setX(double r) {
	x = r / k;
}

void PointPressure::setY(double P) {
	y = P / ratio;
}