#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter size: ";
    cin >> n;

    char arr[n + 1];
    cin >> arr;

    for(int i = 0; i < n; i++){
        if(arr[i] != arr[n-1-i]){
            cout << "Not a palindrome" << endl;
            return 0;
        }
    }
    cout << "Palindrome" << endl;
    return 0;
}