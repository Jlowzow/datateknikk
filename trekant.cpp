// trekant.cpp
// Oppgave 2

#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

static double PI = acos(-1);
bool stoppkode = false;

double trekantAreal(double, double, double);
double lesInn(string);
vector<double> trekantVinkler(double, double, double);
bool triangel(double, double, double);
void intro();

int main(){
    
    intro();

    while(!stoppkode){
        double a, b, c;
        a = lesInn("a");
        b = lesInn("b");
        c = lesInn("c");
        
        cout << endl;

        if (triangel(a, b, c)){
            vector<double> vinkler = trekantVinkler(a, b, c);
            
            cout << "Vinklene i trekanten er: " << endl;


//          for(double n : vinkler){ Den enkleste måten å loope gjennom en container, virker ikke før C++11. plz fix
            for(int n = 0; n < vinkler.size(); n++){
                cout << vinkler[n] * 180 / PI << '\n';
            }
            cout << endl;   
            cout << "Arealet er: " << trekantAreal(a, b, c) << endl; 


        } else {

            cout << "Dette er umulig en triangel." << endl;
        }
    }
}

double trekantAreal(double a, double b, double c){ //Bruker herons formel til å regne ut arealet
    double s = (a + b + c) / 2;
    double A = sqrt( s * (s-a) * (s-b) * (s-c));
    return A;
}

vector<double>  trekantVinkler(double a, double b, double c){ //Benytter cosinus setningen til å regne ut vinkler
                                                              //Returnerer en vector med verdiene.
    vector<double> vinkler(3);
   

    vinkler[0] = ((pow(a, 2) + pow(b, 2) - pow(c, 2))) / ( 2 * a * b);
    vinkler[1] = ((pow(b, 2) + pow(c, 2) - pow(a, 2))) / ( 2 * b * c);
    vinkler[2] = ((pow(a, 2) + pow(c, 2) - pow(b, 2))) / ( 2 * a * c);
    
    vinkler[0] = acos(vinkler[0]);
    vinkler[1] = acos(vinkler[1]);
    vinkler[2] = acos(vinkler[2]);

    return vinkler;
}
// Får vinklene fra brukeren, setter stoppBit til 1 om den får en 0.
double lesInn(string melding){
    cout << melding + ": ";
    double a;
    cin >> a; 
    if(a == 0){
        stoppkode = true;}
    return a;
}
// Funksjon som tester om dette er en triangel.
bool triangel(double a,double b,double c){
    bool x = true;

    if(a + b < c || a + c < b || b + c < a){
        x = false;
    }
    if(a == 0 | b == 0 | c == 0){
        x = false;
    }
    return x;
}

void intro(){
    cout << "Dette programmet finner vinklene (i grader) og arealet til en trekant. Skriv inn lengdene, avslutt ved a la en side være 0." << endl;
}
