#include "enkelparser.h"
#include "mclclass.h"
#include "arrayHjelp.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	double sensorSD = 50;
	double xpos	= 5;
	int npartikler = 200;
	cout << "test" << endl;
	mcLokaliserer mcl(npartikler, xpos, sensorSD);
	enkelParser pars;

	cout << pars.parsString("sin(pi/2)", 1) << endl;
}
