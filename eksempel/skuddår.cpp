#include <iostream>
using namespace std;

bool skuddaar(int aar){    // Funksjonen returnerer 1 dersom skuddår.
    bool skudd = false;

    if (aar % 4 == 0){
        skudd = true;
    }

    if ((aar % 100 == 0) && (aar %400 != 0)){
        skudd = false;
    }

    return skudd;
}

int main(){

    int n;

    cout << "Er det et skuddår? ";
    cin >> n;

    bool x = skuddaar(n);

    cout << x << endl;

    return 0;
}
