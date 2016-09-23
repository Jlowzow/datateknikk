#include <iostream>
#include <cmath>
using namespace std;


void Introduksjon(double a, double b){
    cout << "Finn punkt på en hyperbel der a = " << a << " og b = " << b << endl;
}

double Innlesing(){
    double d;
    cin >> d;
    return d;
}

double f(double X, double a, double b){
    double y;
    
    if(X <= -a || X >= a){
        y = b * sqrt((pow(X,2)/pow(a,2)) - 1);
    } else {
        y = 0;
    }
    return y;
}

void Utskrift(double x, double y){
    cout << "(" << x << "," << y << ")";
}


int main(){

    double X, Y;
    const double a = 4.0;
    const double b = 2.0;
    Introduksjon(a, b);
    X = Innlesing();
    Y = f(X, a, b);
    Utskrift(X, Y);
}
