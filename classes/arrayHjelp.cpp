#include <array>
using namespace std;

void bytt(double &a, double &b){
    double helper = a;
    a = b;
    b = helper;
}

void sorter(double *x, int n){

    for(int i = 0; i < n - 1; i++){
        for(int j=i+1; j < n; j++){
            if(x[i] < x[j]){
                bytt(x[i], x[j]);
            }
        }
    }
}

void reverser(double *x, int n){
    int halv = n / 2;

    for(int i = 0; i < halv; i++){
        bytt(x[i], x[n - i - 1]);
    }
}

