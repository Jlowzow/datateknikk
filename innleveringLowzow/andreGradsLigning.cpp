#include <iostream>
#include <cmath>
#include <string>
#include <math.h>
#include <vector>
#include <complex>

using namespace std::complex_literals;
using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::complex;
using std::string;

void introduksjon();
double lesInn(string);  //Vil argumentere for at det er bedre å skrive main funksjonen til sist. alltid.
double radikand(double, double, double);
vector<complex<double>> finRotter(double, double, double);
void skrivUtSvar(double, double, double);

int main(){
    introduksjon();
    double a, b, c, r;
    a = lesInn("a");
    b = lesInn("b");
    c = lesInn("c");
    r = radikand(a, b, c);
    skrivUtSvar(a, b, r);
    return 0;
}

void introduksjon(){
    cout << "Dette programmet løser 2.gradsligninger, Du blir bedt om å skrive inn a, b og c ledd" << endl;
}

double lesInn(string melding){
    cout << melding + ": ";
    
    double ret;
    cin >> ret;
    return ret;
}

double radikand(double a, double b, double c){
    double r;

    r = pow(b, 2) - 4*(a * c);

    return r;
}
//finner røttene og samler dem i en vektor. Returnerer denne vektoren.
//Har lekt med komplekse tall i C++
vector<complex<double>> finnRotter(double a, double b, double r){
    vector<complex<double>> rotter;
    complex<double> x1, x2;

    if(r >= 0){
        x1 = (-b + sqrt(r)) / (2 * a);
        x2 = (-b - sqrt(r)) / (2 * a);
    }else if(r < 0){
        x1 = (-b/(2*a) + (1i * sqrt(abs(r)) / (2 * a)));
        x2 = (-b/(2*a) - (1i * sqrt(abs(r)) / (2 * a)));
    }

    rotter.push_back(x1);
    rotter.push_back(x2);

    return rotter;
    
}
// Skriver ut røttene. Tester om det er en imaginær del og formaterer svaret deretter.
void skrivUtSvar(double a, double b, double r){
    vector<complex<double>> losning;

    losning = finnRotter(a, b, r);
    cout << endl;
    
    if(imag(losning[0]) != 0){
        cout << "x1 = " << real(losning[0]) << " + " << imag(losning[0]) << "j " <<  endl;
        cout << "x2 = " << real(losning[1]) << " + " << imag(losning[1]) << "j " <<  endl;
    } else {
        cout << "x1 = " << real(losning[0]) << endl;
        cout << "x2 = " << real(losning[1]) << endl;
    }
}
