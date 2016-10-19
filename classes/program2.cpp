#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <math.h>
#include "program2.h"
#include "arrayHjelp.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::stringstream;
using std::ifstream;
using std::getline;
using std::sin;
using std::cos;
using std::ofstream;

void program2(string fil){
    int n = 361; 
    double sin[361];
    double cos[361];

    string line;
    string hjelper;

    ifstream data(fil);
    if (data.is_open()){

        getline(data,line);
        int x = 0;
        int tmp;
        while(getline (data,line))
        {
            stringstream ss(line);
            ss >> tmp >> sin[x] >> cos[x];
            x++;
        }
    }    
    data.close();
        
    double diff[361];
    differens(sin, cos, diff, 361);
    
    int v;
    double m = min(sin, v, n);
    cout << v << " " << m << endl;
    
    m = max(sin, v, n);
    cout << v << " " << m << endl;
    m = min(cos, v, n);
    cout << v << " " << m << endl;
    m = max(cos, v, n);
    cout << v << " " << m << endl;
    
    ofstream utfil("graf.dat"); 
    for(int i = 0; i < n; i++) {
    utfil << i << setw(15) << diff[i] << endl;
    }
    utfil.close(); 
    system("python plotter.py");
    
    sorter(sin, n);
    sorter(cos, n); 

    utfil.open("graf.dat"); 

    for(int i = 0; i < n; i++) {
        utfil << i << setw(15) << sin[i] << setw(15) << cos[i] << endl;
    }
    utfil.close();
    system("python plotter.py");

    

}

