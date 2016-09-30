// veketrelowz.cpp


#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string signtest(int n){      // funksjon som tester fortegn på integers, returnerer string
    string svar = "positivt"; // definerer stringen svar, og setter den til positivt.

    if(n < 0){
        svar = "negativt";   // Endrer svar til negativt om dette er tilfelle
    }
    if(n == 0){
        svar = "null";
    }

    return svar; 
}



int main() {
    
    cout << "Dette programmet tester fortegn på heltall og lager løpende gjennomsnitt" << endl;
    cout << "avslutt med 999" << endl;
    // Definerer variabler 
    int n = 0;
    int sum = 0;
    double x;
    double gjennomsnitt;

        while(cin >> x && x != 999 && floor(x) == x) //leser inn tall så lenge det er integers og ikke 999
        {
        n++;                        //Teller syklusser
        sum = sum + x;              //Summerer alle tallene
        gjennomsnitt = sum / (double)n;                     //Regner ut gjennomsnitt i farten
        cout << signtest(x)+ ", gjennomsnitt: " << gjennomsnitt << endl;   //Skriver ut signtest av x og gjennomsnittet
        }   
    
    if(n == 0){
        cout << "du leste ikke inn noe heltall" << endl;
    } else if(x == 999) {
        cout << "avsluttet med kode 999" << endl;
    } else{
        cout << "feil input!" << endl;
    }

    return 0;
    
}   
