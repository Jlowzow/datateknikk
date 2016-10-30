//mcl.cpp
#include <vector>

using std::vector;

void mcl1D(int *X0, int n, double bevegelse, double sensor) //mcl alogoritmen skal ta tabell med mulige possisjoner, bevegelse og sensorinput
{
	int X[n];
	vector<vector<double>> X1;
		 
	for (int i = 0; i < n ; n++){
		X1[i].push_back(X0[i] + bevegelse);
	}
}
		
