#include <iostream>
#include "signal.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using std::cout;
using std::endl;
using std::ofstream;
using std::setw;

void program1(){
	srand(time(NULL));

	ofstream utfil;
	utfil.open("graf.dat");
	utfil << "x" << setw(15) << "sin(x)" << setw(15) << "cos(x)" << endl;

	int n = 361;
	double y1[n];
	double y2[n];

	for(int i = 0; i < n; i++){
		y1[i] = noise(sin(dToRad(i)));
		y2[i] = noise(cos(dToRad(i)));
		utfil << i << setw(15) << y1[i] << setw(15) << y2[i] << endl;
	}
	ofstream utfil2;
	utfil2.open("graf.txt");
	utfil.close();

	std::ifstream src("graf.dat", std::ios::binary);

	utfil2 << src.rdbuf();

	utfil2.close();
	src.close();

	system("python plotter.py");
}

