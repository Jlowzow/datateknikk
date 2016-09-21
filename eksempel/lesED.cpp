#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){

    ifstream innfil;

    string navn, fornavn;
    int alder, karakter;

    innfil.open("ED.dat");

    while(!innfil.fail()){
        innfil >> navn >> fornavn >> alder >> karakter;
        cout << alder << endl;
    }

    innfil.close();
}
