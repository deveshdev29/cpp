#include <iostream>
using namespace std;


bool isPrime(int num){
    for(int i = 2; i < num; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){

    int a,b;
    cout << "Enter first number  ";
    cin >> a;
    cout << "Enter second number  ";
    cin >> b;

    for(int i = a; i <= b; i++){
        if(isPrime(i)){
            cout << i << endl;
        }
    }
    return 0;
}