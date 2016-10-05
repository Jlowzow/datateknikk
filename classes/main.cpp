#include <iostream>
#include <string>
#include "arrayHjelp.h"
#include <array>

using namespace std;


int main(){
    
    const int n = 5;
    double X[n];


    for(int i = 0; i < n; i++  ){
        cin >> X[i];
    }
    
    cout << endl;

    
    sorter(X, n);

    for(int v = 0; v < n; v++  ){
        cout << X[v] << endl;
    }
    
    cout << endl;
    
    reverser(X, n);    
    for(int v = 0; v < n; v++  ){
        cout << X[v] << endl;
    }
}
