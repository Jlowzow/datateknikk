#include <iostream>
#include <math.h>
using namespace std;


int main()
{
    int z, x, c, v; //definer fire variabler
    cout << "skriv fire tal og få dem vurdert: ";
    try{                                        // Vi vil bare ha heltall, og vil ha en feilmelding om annet.
        cin.exceptions(std::istream::failbit); // skrur på feilmeldinger
        cin >> z >> x >> c >> v;
    }
    catch( exception e)                         // griper feilmelding og gir medling til bruker
    {
        cout << "noe gikk galt" << endl;
    }

    int sum;
    sum = z+x+c+v;
    cout << sum << endl;

    double gjennomsnitt = sum / 4.0;
    cout << gjennomsnitt << endl;


    if( gjennomsnitt < 3){
        cout << "Under norm." << endl;
    }
    else if (gjennomsnitt > 7){
        cout << "over norm." << endl;
    }
    else {
        cout << "norm." << endl;
    }


// finn ut om talet er heiltall
    
//    cout << fmod(gjennomsnitt, 1) << endl;

    if( fmod(gjennomsnitt, 1)  == 0){
        cout << "gjennomsnittet er heltall." << endl;
    }

    return 0;
}

