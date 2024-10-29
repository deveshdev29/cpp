#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> numbers;
    int n;
    cout << "How many numbers you want to enter? ";
    cin >> n;

    for(int i = 0; i < n; i++){
        int num;
        cout << "Enter a number: ";
        cin >> num;
        numbers.push(num);
    }
    while(!numbers.empty()){
        int num = numbers.top();
        cout << num << " ";
        numbers.pop();
    }
    return 0;
}