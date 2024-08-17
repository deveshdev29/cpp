#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){

    int start = 0;
    int end = n - 1;
     
     while(start <= end){

        int mid = (start + end) / 2;

        if(arr[mid] == key){
            return mid;
        }else if(arr[mid] > key){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
     }
    return -1;
}

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
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int key;
    cout << "Enter key: ";
    cin >> key;

    cout << "Sorting the array" << endl;
    selectionSort(arr, n);
    
    cout << "Sorted array is ";
    printArray(arr, n);

    cout << "Index of the key is " << binarySearch(arr, n, key);

    return 0;
}