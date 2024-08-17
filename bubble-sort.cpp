#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n){

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

        }
    }
}

void printArray(int arr[], int n){
        for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){

    int n;
    cout << "Enter size of the array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Unsorted array is ";
    printArray(arr, n);
    cout << endl;


    cout << "Sorted array is ";
    bubbleSort(arr, n);
    printArray(arr, n);
    cout << endl;

    return 0;
}