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
    int max_num = arr[0];
    int min_num = arr[0];


    for(int i = 0; i < n;i++){   
        max_num = max(max_num,arr[i]); // By using max and min functions
        min_num = min(min_num,arr[i]);

        if(max_num < arr[i]){  // By using logic
            max_num = arr[i];
        }if(min_num > arr[i]){
            min_num = arr[i];
        }
    }
    cout << "Max number is " << max_num << endl;
    cout << "Min number is " << min_num << endl;
    return 0;
}