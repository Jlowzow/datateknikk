#include <iostream>
#include <string>

using namespace std;

int main(){
    string a;

    cin >> a;

    for(char &c : a){
        c = toupper(c);
        cout << c << endl;
    }
    
    for(int i = a.size(); i > 0; i--){
        cout << a[i] << endl;
    }
}
