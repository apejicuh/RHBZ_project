#include <iostream>;
#include <vector>;
#include "Wave.h";
#include "PointPressure.h";

using namespace std;

int main() {
	Wave wave(3000, 150000);
	int i;
	for (i = 0; i < 178; i++) {
		wave.step();
	}
	vector<PointPressure> pV = wave.getWave();
	for (i = 0; i < pV.size(); i++) {
		cout << pV[i].P;
	}
	return 0;
}