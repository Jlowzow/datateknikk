//mcl.cpp
#include <vector>

using std::vector;

void mcl1D(int *X0, int n, double hastighet, double sensor) //mcl alogoritmen skal ta tabell med mulige possisjoner, bevegelse og sensorinput
{
	int X[n];
	vector<vector<double>> X1;
		 
	for (int i = 0; i < n ; n++){
		X1[i].push_back(X0[i] + bevegelse(hastighet); //hvor mye tror vi at vi bevegde oss?
		X1[i].push_back(sensor(X1[0]);			// Hvordan setmmer dette med kartet?
	}
}

double bevegelse(double hastighet){
	double dt;
	return hastighet * dt;
}

double sensor(double xpos){
	double avvik;
	return avvik;
}

vector<double> vektetRandom(vector<vector<double>> posisjoner){
	vector<double> nyePartikler;
	return nyePartikler
}
