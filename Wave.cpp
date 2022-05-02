#include "Wave.h"
#include "PointPressure.h"
#include <QVector>
#include <cmath>

using namespace std;

Wave::Wave(double T, double P) {
	this->T = T;
	addPoint(0, P);
}

void Wave::addPoint(double r, double P) {
	this->pointPressures.push_back(PointPressure(r, P));
}

void Wave::step() {
	nuw_r += 100;
	double P = step(nuw_r);
	addPoint(nuw_r, P);
}

double Wave::step(double r) {
    double P = 1.5 * T / (pow(M_PI, 2) * pow(r, 3));
	return P;
}
