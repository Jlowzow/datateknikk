#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
	//initializing variables 
	double a=0;
	double b=0;
	double c=0;
	double h=0;
	double A=0;
	double s=0;
	double o=0;
	double ac=0;
	double ab=0;
	double bc=0; 

	while (true) {



	cout << "\n" ;
 	cout << "|          .\n" ;
 	cout << "|        /  \\\n" ;
 	cout << "|     c /    \\ b\n" ;
 	cout << "|      /______\\\n" ;
 	cout << "|          a\n" ;
	cout << "-------------------------------------------------------\n" ;
	cout << "please enter a, b and c length values \n" ;
	cout << "..";
	cin >> a >> b >> c; 
	cout << "a: " << a << " b: " << b << " c: " << c << "\n"; 
	if ( a==0 || b == 0 || c==0 ) {
		return 0;
	}
	//benytter herons formel
	// s= 0.5*(a+b+c)
	// A=sqr(s(s-a)(s-b)(s-c))
	else {
		s = 0.5 * (a+b+c);
		o = 2*s;
		A= s * ((s-a) * (s-b) * (s-c)) ;
		A=sqrt(A);
		//A a*h /2
		h=(2*A) /a;

		// dont work, why?
		ac= acos(a/b);
		ab= acos(b/a);
		bc= acos(b/c);
	}

	cout << "Omkrets=" << o << "\nAreal=" << A <<"\nHøyde="<< h <<"\n";
	cout << "ac=" << ac << " ab=" << ab << " bc=" << bc << "\n";

 	// exit this shiiiit
	

	}
	return 0;
}