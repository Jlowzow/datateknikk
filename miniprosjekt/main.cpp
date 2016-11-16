#include "enkelparser.h" //Parseren som benytter exprtk.hpp
#include "mclclass.h"	//Klassen som inneholder MCL alogoritmen
#include "arrayHjelp.h" //For sortering, max, min for tabeller og vektorer
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
enkelParser pars;	//Definerer objektet som skal parse tekststrenger.
int n;
double * testdata; //skal kunne ta vare på en tabell på heapen.
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
	vector< vector<string> >::const_iterator linje;	//looper ved hjelp av iterators.
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
			getline(infil, t2); //bruker getline etter vi har fått navnet slik at hele resten av linjen blir satt i samme string. Dette er matematiske uttrykk som kan ha mellomrom.
			nyttkart(t1,t2);
		}
	}
	infil.close();
}

void listkart(){
	int i = 1;
	for(auto const& linje: kartl){ // looper gjennom alle linjer og kolonner i biblioteket. gjør dette med den todimensjonale vectoren kartl;
		cout << i << ". ";
		i ++;
		for(auto const& kol: linje){
			cout << kol << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void slettDuplikater(){
	set<vector<string> > s; // set tar bare vare unike elementer.
	unsigned size = kartl.size(); //Vi vet ikke hvor stor vektoren er.
	for( unsigned i = 0; i < size; i++) s.insert( kartl[i]);
	kartl.assign( s.begin(), s.end()); //kopier vektoren til set og tilbake.
}

//Genererer testdata utifra et kart i biblioteket.
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
	cout << "-------------Testdata er klar-------------" << endl;
}
//Sammenligner testdata med et kart valgt av brukeren.
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

	cout << "----------------Start Estimering------------" << endl;

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

	cout << "Algoritmen er kjørt " << l + 1 << " ganger" << endl;

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
		cout << "3. Lagre til fil" << endl;
		cout << "4. Åpne kartbibliotek fra fil" << endl;
		cout << "5. lag testdata" << endl;
		cout << "6. Finn posisjon" << endl;
		cout << "7. Slett kart" << endl;
		cout << "8. Slett duplikater" << endl;

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
		if(valg == 7){
			listkart();
			cout << "Hvilke kart vil du slette?" << endl;
			int slett;
			cin >> slett;
			kartl.erase(kartl.begin() + slett - 1);
		}
		if(valg == 8){
			slettDuplikater();
		}
	}
}

int main(){
	
	cout << "Velkommen til dette kartbiblioteket og demonstrasjon av hvordan vi kan finne lokasjon ved hjelp av \"Sekvensiell Monte Carlo\"-alogoritmen. " << endl;
	cout << "Bruk vedlagte eksempelkart for å teste, eller skriv inn matematiske utrykk for å representere landsskapet." << endl;
	cout << "Begynn med å lage testdata, så kan du teste algoritmen med \"Finn Posisjon\"" << endl;
	opnekartfil("kart.txt");

	meny();
	
}
