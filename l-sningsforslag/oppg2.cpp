/*
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

#include <iomanip>
using namespace std;

double PI = acos(-1);

double f(double x) {

	x = sin(PI * x / 8) + 2 * cos(PI * x / 5);

	return x;
}

int main() {
	cout << PI << endl;
	vector<double> vec;

	for (int i = 1; i < 41; i++) {
		vec.push_back(f(i));
	}
	
	ofstream utfil;
	utfil.open("GRAF.DAT");

	unsigned n = 1;
	for (double i : vec) {
		utfil << n << setw(10) << i << endl;
		n++;
	}

	utfil.close();

	

	system("grafikk.exe");

	return 0;
}
*/