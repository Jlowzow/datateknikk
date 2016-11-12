#include "enkelparser.h"
#include "mclclass.h"
#include "arrayHjelp.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<string>> kartl;

void nyttkart(string navn, string funk){
	vector<string> temp;
	temp.push_back(navn);
	temp.push_back(funk);
	kartl.push_back(temp);
}

void lagrekart(string fil){
	ofstream utfil;
	vector< vector<string> >::const_iterator linje;	//tester iterators
	vector<string>::const_iterator kol;				

	for (linje = kartl.begin(); linje != vec.end(); ++linje)
	{
		for(kol = linje->begin(); kol != linje->end(); kol++)
		{
			utfil << *kol;
		}
		utfil << endl;
}

int main(){
	double sensorSD = 50;
	double xpos	= 5;
	int npartikler = 200;
	cout << "skriv inn et utrykk: " << endl;
	enkelParser pars;

	string regn;
	cin >> regn;
	cout << endl;
	mcLokaliserer mcl(npartikler, xpos, sensorSD, regn);

	cout << pars.parsString(regn, 1) << endl;
}