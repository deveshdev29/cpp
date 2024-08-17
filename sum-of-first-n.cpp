#include <iostream>
using namespace std;

int CalSum(int num){

    int sum;
    sum = num * (num + 1) / 2;
    return sum;
}

int main(){

    int n;
    cout << "What's n ?? ";
    cin >> n;

    cout << "Sum is " << CalSum(n) << endl;
    return 0;
}
