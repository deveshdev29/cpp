#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int n;
    cout << "What is the number?? ";
    cin >> n;
    int num = n;

    int digits = 0;
    int sum = 0;

    while(n > 0){
        int last = n % 10;
        digits++;
        n = n/10;
    }
    n = num;
    while(n > 0){
        int last = n % 10;
        sum += pow(last, digits);
        n = n/10;
    }
    if(sum == num){
            cout << "ARMSTRONG NUMBER" << endl;
            return 0;
        }else{
            cout << "NOT AN ARMSTRONG NUMBER" << endl;
            return 0;
        }
    return 0;
}