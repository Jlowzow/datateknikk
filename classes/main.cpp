// main.cpp

#include <iostream>
#include "signal.h"
#include "program1.h"
#include "program2.h"
#include <math.h>
#include <cstdlib>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ofstream;
using std::string;

int main(){
	
	string filnamn = "graf.txt";

	program1();
	program2(filnamn);
	
    return 0;

}
