#include <iostream>
using namespace std;

int firstOcc(int arr[], int n, int i, int key){

    if(i==n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstOcc(arr, n, i+1, key);
}

int lastOcc(int arr[], int n, int i, int key){

    if(i==0){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return lastOcc(arr, n, i-1, key);
}

int main(){

    int n;
    cout << "Enter size of the Array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int search;
    cout << "What number you wanna search? ";
    cin >> search;
    
    cout << firstOcc(arr, n, 0, search) << endl;
    cout << lastOcc(arr, n, n-1, search) << endl;
    return 0;
}