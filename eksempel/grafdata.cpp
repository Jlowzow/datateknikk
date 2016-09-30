#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main (){
    
    ofstream utfil;
    utfil.open("graf.dat");

    utfil.setf(ios::fixed, ios::floatfield);
    utfil.precision(3);

    double x;
    double y;

    utfil<<"X                 Y"<<endl;

    for(int n=-10;n<=10;n++){
        x=0.1*n;
        y = x * x;
        utfil<<setw(10)<< x << setw(20) << y << endl;
    }

    utfil.close();

}
