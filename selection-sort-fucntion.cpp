#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){

    for(int i = 0; i < n - 1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void printArray(int arr[], int n){

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Unsorted array" << endl;
    printArray(arr, n);

    cout << "Sorted array" << endl;
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}