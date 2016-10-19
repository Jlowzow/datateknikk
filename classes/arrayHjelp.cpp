#include <array>
using namespace std;

void bytt(double &a, double &b){
    double helper = a;
    a = b;
    b = helper;
}

void sorter(double *x, int n){

    for(int i = 0; i < n  ; i++){
        for(int j=i+1; j < n ; j++){
            if(x[i] > x[j]){
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

void differens(const double *a, const double *b, double *diff, int n){
    for(int i = 0; i < n; i++){
        diff[i] = a[i] - b[i];
    }
}

double min(const double *a, int &vinkel, int n)
{
	double x = a[0];
	for(int i = 0; i < n; i++){
		if(x > a[i]){
			x = a[i];
			vinkel = i;
		}
	}
	return x;
}

double max(const double *a, int &vinkel, int n){
	double x = a[0];
	for(int i = 0; i < n; i++){
		if(x < a[i]){
			x = a[i];
			vinkel = i;
		}
	}
	return x;
}


