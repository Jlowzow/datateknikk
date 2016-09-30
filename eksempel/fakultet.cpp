
#include <iostream>
using namespace std;

int fakultet(int inn) //funksjonen som skal regne  ut fakultetet. Tar int x.
{
    int fakultet;

    for(int n = 1; n <= inn; n++){
        fakultet += n;
    }

    return fakultet;
}
int main()
{
    int N;
    int sum=0;

    cout << "Finn fakultet: ";
    cin >> N;

    cout << fakultet(N) << endl;

    return 0;
}
