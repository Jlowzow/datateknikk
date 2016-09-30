//Et prgram som regner gjennomsnitt og behandler det
//Jan-Kristian Mathisen, SKSK 2016
#include <iostream>
using namespace std;


int main() {
	
	//initierer inputvariablene
	int in_1, in_2, in_3, in_4;

	//initierer variablen for gjennomsnitt
	double mean; //double  for å få til desimaler 

	//tar inn tall 
	cout << "Skriv fire tall du ønkser å regne gjennomsnitt av og behandele\n";
	cin >> in_1 >> in_2 >> in_3 >> in_4; 
	//cout << "Du skrev inn" << in_1 <<", "<< in_2 <<", "<< in_3 <<", "<< in_4 << endl;  //debug


	//regner gjennomsnitt; sum/antall
	mean = (in_1 + in_2 + in_3 + in_4) / 4.0; // må benytte .0 for å få desimaler
	cout << "Gjennomsnittet er: "<< mean << ", og det er ";

	//skriver under norm hvis under 3
	if (mean < 3) {
		cout << "Under normal";
	}
	//hvis ikke skriver over norm hvis over 7
	else if (mean > 7) {
		cout << "Over normal";
	} 
	// ellers må det være mellom 3 og 7
	else {
		cout << "Normal";
	}

	//sjekk for heltall
	// heltall hvis snitt verdi er det samme som avrundet snittverdien
	if (mean == (int)mean) {
		cout << " og heltall";
	}
	//skriver ut linjen
	cout << endl;

	//Formål nådd, lukker program.
	return 0; 
}


