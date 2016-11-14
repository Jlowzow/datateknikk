#include "enkelparser.h"
#include "mclclass.h"
#include "arrayHjelp.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
enkelParser pars;
int n;
double * testdata;
vector< vector<string> > kartl;

void nyttkart(string navn, string funk){
	vector<string> temp;
	temp.push_back(navn);
	temp.push_back(funk);
	kartl.push_back(temp);
}

void lagrekart(string fil){
	ofstream utfil;
	utfil.open(fil);
	vector< vector<string> >::const_iterator linje;	//tester iterators
	vector<string>::const_iterator kol;				

	for (linje = kartl.begin(); linje != kartl.end(); ++linje)
	{
		for(kol = linje->begin(); kol != linje->end(); kol++)
		{
			utfil << *kol << " ";
		}
		utfil << endl;
	}
	
}

void opnekartfil(string fil){
	ifstream infil;
	infil.open(fil);
	
	string t1, t2;

	while( !infil.fail()){
		infil >> t1;
		if(!infil.fail()){
			getline(infil, t2);
			nyttkart(t1,t2);
		}
	}
	infil.close();
}

void listkart(){
	int i = 0;
	for(auto const& linje: kartl){
		cout << i << ". ";
		i ++;
		for(auto const& kol: linje){
			cout << kol << " ";
		}
		cout << endl;
	}
	
}

void lagTestData(){
	listkart();
	cout << "hvilke kart vil du generere data med?" << endl;
	int k;
	cin >> k;
	cout << "Utgangspossisjon? (heltall)" << endl;
	int x1;
	cin >> x1;
	cout << "x2? " << endl;
	int x2;
	cin >> x2;
	n = x2 - x1;
	
	testdata = new double[n];
	cout << "test" << endl;
	int j = 0;
	cout << kartl[k-1][0] << endl;
	for(int i = x1; i < x2+5; i += 5){
		testdata[j] = pars.parsString(kartl[k-1][1], i);
		cout << i << endl;
		j++;
	}
}

void estimerPos(){
	listkart();
	cout << "hvilke kart vil du sammenligne data med?" << endl;
	int i;
	cin >> i;
	cout << kartl[i-1][1] << endl;
	cout << "Gjett utgangsposisjon: " << endl;
	double Xpos;
	cin >> Xpos;


	cout << "Standardavvik til høydesensor: " << endl;
	double sensorSD;
	cin >> sensorSD;

	cout << "Antall partikler i partikkelfilteret:" << endl;
	int npartikler;
	cin >> npartikler;
	mcLokaliserer mcl(npartikler, Xpos, sensorSD, kartl[i-1][1]);
	
	int l = -1;
	for(int k =(int)Xpos; k < n + (int)Xpos + 5; k += 5){
		mcl.oppdaterPartikler(5);
		l++;
		mcl.oppdaterVekter( testdata[l]);
		mcl.resample();
	}
	vector<double> hypoteser;
	vector<double> vekter;
	mcl.oppdaterVekter(testdata[l]);
	hypoteser = mcl.getPartikler();
	vekter = mcl.getVekter();

	boblesorter(hypoteser, vekter);
	for(int n = 0; n < hypoteser.size(); n++){
		cout << hypoteser[n] << " " << vekter[n] << endl;
	}
	cout << endl;
	cout << "Spredning på hypotesene: " << hypoteser.back() - hypoteser[0] <<endl;
	double temp = max(vekter);
	int pos = find(vekter.begin(), vekter.end(), temp) - vekter.begin();
	
	cout << "beste estimat: " << hypoteser[pos] << endl;
	cout << endl;


}

void meny(){
	
	int valg = 1;
	while(valg != 0){
		cout << "1. List kart" << endl;
		cout << "2. Legg inn nytt kart" << endl;
		cout << "3. Lagre" << endl;
		cout << "4. Åpne" << endl;
		cout << "5. lag testdata" << endl;
		cout << "6. Finn posisjon" << endl;

		cin >> valg;

		if(valg == 1){
			listkart();
		}

		if(valg == 2){
			cout << "Navn på kartet" << endl;
			string navn;
			cin >> navn;

			cout << "Kartfunksjon:" << endl;
			string kartf;
			cin.ignore();
			getline(cin, kartf);

			nyttkart(navn, kartf);

		}
		if(valg == 3){
			cout <<"Filnavn: " << endl;
			string fil;
			cin >> fil;
			lagrekart(fil);
		}
		if(valg == 4){
			cout <<"Filnavn: " << endl;
			string fil;
			cin >> fil;
			opnekartfil(fil);
		}
		if(valg == 5){
			lagTestData();	
		}
		if(valg == 6){
			estimerPos();
		}
	}
}

int main(){
	
	cout << "Velkommen til dette kartbiblioteket og demonstrasjon av hvordan vi kan finne lokasjon ved hjelp av Sekvensiell Monte Carlo alogoritmen. " << endl;
	cout << endl;
	opnekartfil("kart.txt");

	meny();
	
}
