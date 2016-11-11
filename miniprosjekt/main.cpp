#include "enkelparser.h"
#include "mclclass.h"
#include "arrayHjelp.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<string>> kartl;

void nyttkart(string funk){
	vector<string> temp;
	temp.push_back(funk);
	kartl.push_back(temp);
}

void lagrekart(string fil){
	ofstream utfil;
}

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
