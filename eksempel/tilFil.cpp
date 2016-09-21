#include <fstream>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    
    int y;


    ofstream utfil;

    int x = 5;

    utfil.open("test.dat");
    utfil<<"Dette er en testfil" << endl;

    int i = 1;
    while(i <= 5){
        utfil<< i << " " << sqrt(i) << endl;
        i++;
    }
    utfil.close();
}
