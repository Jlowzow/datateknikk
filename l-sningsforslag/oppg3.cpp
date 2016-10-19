/*
#include <iostream>

using namespace std;

int storleik;

void Innlesing(int *x) {
	cout << "Skriv inn tall og få dem sortert! " << endl;
	storleik = sizeof(x);
	for (int n = 0; n <= storleik; n++) {
		cin >> x[n];
	}
	cout << endl;
}

void Utskrift(int *x) {
	for (int n = 0; n <= storleik; n++) {
		cout << x[n] << endl;
	}
}

void byttom(int &a, int &b) {
	int hjelper = a;
	a = b;
	b = hjelper;
}

void Sortering(int *x) {
	for (int i = 0; i <= storleik; i++) {
		for (int j = 0; j <= storleik; j++) {
			if (x[j] > x[i]) {
				byttom(x[j], x[i]);
			}
		}
	}
}
int main() {
	int T[5];
	Innlesing(T);
	Sortering(T);
	Utskrift(T);
	system("pause");
	return 0;
}

*/