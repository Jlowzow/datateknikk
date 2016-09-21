#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    ofstream utfil;

    string navn, fornavn, alder, karakter;

    utfil.open("ED.dat");

    
    for(int i = 0; i < 10; i++){

        cin >> navn >> fornavn >> alder >> karakter;
        utfil << navn << " " << fornavn  << " "<< alder  << " "<< karakter;
        utfil << endl;
    }

    utfil.close();
}
