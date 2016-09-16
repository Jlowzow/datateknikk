// trekant.cpp
// Oppgave 2

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

static double PI = acos(-1);

double trekantAreal(double l, double h){
    double a = (l * h) / 2;
    return a;
}

vector<double>  trekantVinkler(double a, double b, double c){
    vector<double> vinkler(3);
   

    vinkler[0] = ((pow(a, 2) + pow(b, 2) - pow(c, 2))) / ( 2 * a * b);
    vinkler[1] = ((pow(b, 2) + pow(c, 2) - pow(a, 2))) / ( 2 * b * c);
    vinkler[2] = ((pow(a, 2) + pow(c, 2) - pow(b, 2))) / ( 2 * a * c);
    
    vinkler[0] = acos(vinkler[0]);
    vinkler[1] = acos(vinkler[1]);
    vinkler[2] = acos(vinkler[2]);

    return vinkler;
}

double lesInn(string melding){
    cout << melding + ": ";
    double a;
    cin >> a; 

    return a;
}

bool triangel(double a,double b,double c){
    bool x = true;

    if(a + b < c || a + c < b || b + c < a){
        x = false;
    }

    return x;
}

int main(){
    double a, b, c;
    a = lesInn("a");
    b = lesInn("b");
    c = lesInn("c");
    
    if (triangel(a, b, c)){
        vector<double> vinkler = trekantVinkler(a, b, c);
        for(double n : vinkler){
            cout << n * 180 / PI << '\n';
        }
    } else {
        cout << "Dette er umulig en triangel." << endl;
    }

    
}
