//programm0.cpp

#include <iostream>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);

int main() //hovedprogram
{
    double l,b; //Definerer variabler

    cout<<"Hello world!"<<endl;
    cout<< "Skriv inn lengde og bredde: ";
    cin >> l >> b;
    
    double areal = l * b;
    double div = l / b;
    double sum = l + b;
    double sirkel = pi*b*b;

    l++; // øker med 1
    b--; // minker med 1
    

    cout << "Arealet er:  " << areal << endl;
    cout << "Arealet til sirkel en er:  " << sirkel << endl;
    cout << "brøk " << div << endl;
    cout << "sum " << sum << endl;
    cout << "pi " << pi << endl;
    return 0; 

}
