#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    int col;
    cout << "Enter number of col: ";
    cin >> col;

    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    cout << "The 2-D array entered is " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int key;
    cout << "Enter the number whose index you want to find: ";
    cin >> key;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(key==arr[i][j]){
                cout << "The index of the key is " << i << "," << j << endl;
            }
        }
    }
    return 0;
}