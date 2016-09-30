//middel.cpp
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int storleik = 3;
    vector<double> data;
    double inn;
    int n = 0;

    cout << "les in tall og få ut glidende gjennomsnitt: " << endl;

    while( n <= 15)
    {
        cin >> inn;
        data.push_back(inn);
        n++;
        
        if(data.size() > storleik){
        data.erase(data.begin());
        }

        double sum = 0;
        for(double i : data){
            sum = sum + i;
        }
        
        cout << endl;
        double snitt = sum / (double)data.size();

        cout << snitt << endl;
        cout << endl;
    }

}
