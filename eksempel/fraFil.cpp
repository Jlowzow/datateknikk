#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main(){
    
    ifstream innfil;
    innfil.open("test.dat");

    char overskrift[20];
    innfil.getline(overskrift,20);

    double x,y;

    while( !innfil.fail()){
        innfil >> x >> y;
        if(!innfil.fail()){
            cout << x << "  kvadratrot " << y << endl;
        }
    }
    innfil.close();
}
