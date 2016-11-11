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
	cout << "skriv inn et utrykk: " << endl;
	mcLokaliserer mcl(npartikler, xpos, sensorSD);
	enkelParser pars;

	string regn;
	cin >> regn;
	cout << endl;

	cout << pars.parsString(regn, 1) << endl;
}
