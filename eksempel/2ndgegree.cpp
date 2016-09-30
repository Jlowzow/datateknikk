#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main() {
	//initializing variables 
	double a=0;
	double b=0;
	double c=0;
	double sq_exp=0;
	double root1=0;
	double root2=0;

	cout << "please enter a 2nd funcion in this format \n" ;
	cout << "a*x^2 + b*x + c \n" ;
	cin >> a >> b >> c; 
	//cout << "you have entered.. a=" << a << " b=" << b << " c=" c << "\n";;;

	//2nd degree equation: -b /2a +- sqrt(b^2 - 4ac)/2a

	//in both roots the first part is the same
 	root1 = - b / (2 * a);
 	root2 = root1;

 	//multiply the expression inside the for solution evaluation

 	//if positive - two solutions 
 	//if negative - conjugated imaginary solution
 	//if zero - one solution

 	sq_exp = pow(b,2) - ( 4 * a * c);




 	// one root
 	if (sq_exp == 0) {
 		cout << "one root:\n";
 		cout << "x=" << root1 << "\n";
 	}
 	// two roots
 	else if (sq_exp > 0) {
 		cout << "two roots:\n";
 		root1= root1 + sqrt(sq_exp) / (2*a);
 		root2= root2 - sqrt(sq_exp) / (2*a);
 		cout << "x1=" << root1 << "\n x2=" << root2 << "\n";
 	}
 	 	// imaginary solutions
 	else {
 		cout << "imaginary roots\n";
 		// iot work with real numbers  
 		sq_exp = sq_exp * -1;
 		// finishing the equation
 		sq_exp = sqrt(sq_exp);
 		// -------||------
 		sq_exp = sq_exp / (2 * a);

 		// spit out data 
 		cout << "x1=" << root1 << "+"<< sq_exp << "i \n";
 		cout << "x2=" << root1 << "-"<< sq_exp << "i \n";  
 	}
 	// exit this shiiiit
	return 0;
}