#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    for(int i = 0; i < n; i++){
        if(key == arr[i]){
            cout << "Index of the key is " << i << endl;
        }
    }
    return 0;
}