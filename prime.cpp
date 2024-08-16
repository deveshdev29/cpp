#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "What is the number?? ";
    cin >> n;

    for(int i = 2; i < n; i++){
        if(n % i == 0){
            cout << "PRIME" << endl;
            return 0;
        }else{
            cout << "NOT PRIME" << endl;
            return 0;
        }
    }
}
