#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter Height?? ";
    cin >> n;

    for(int i = n; i > 0; i--){
        for(int j = 0; j < n; j++){
            cout << "*";
        }
        n--;
        cout << endl;
    }
}