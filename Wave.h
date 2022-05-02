#pragma once
#include <QVector>
#include "PointPressure.h"

class Wave
{
private:
	const double k = 1;
    QVector<PointPressure> pointPressures;
	double V;
	double T;
	double nuw_r;

public:
	Wave(double T, double P);
	void step();
	double step(double r);
	void addPoint(double r, double P);
    QVector<PointPressure> getWave() {
		return pointPressures;
	};
};



