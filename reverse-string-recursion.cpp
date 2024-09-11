#include <iostream>
#include <string>
using namespace std;

void reverseString(string str, int size){

    if(size==0){
        return;
    }
    cout << str[size-1];
    reverseString(str, size-1);
}
int main(){

    string str;
    getline(cin, str);

    int n = size(str);
    reverseString(str, n);
    return 0;
}