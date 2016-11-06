#include <array>
#include <vector>

using namespace std;

void bytt(double &a, double &b){
    double helper = a;
    a = b;
    b = helper;
}

void bytt(vector<double> & vec, int i, int j){
	double helper = vec[i];
	vec[i] = vec[j];
	vec[j] = helper;
}

void boblesorter(vector<double> & vec){
	int lengde = vec.size();

	for(int i = 0; i < lengde; i++){
		bool byttet = false;
		for(int j = 0; j < lengde - (i+1); j++){
			if(vec[j] > vec[j+1]){
				bytt(vec, j, j+1);
				byttet = true;
			}
		}
		if (!byttet) break;
	}
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

double max(vector<double> & vec){
	double x = vec[0];
	for(int i = 0; i < vec.size(); i++){
		if(x < vec[i]){
			x = vec[i];
		}
	}
	return x;
}
