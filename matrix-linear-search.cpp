#include <iostream>
using namespace std;

int main(){

    int row;
    cout << "Enter number of Rows: ";
    cin >> row;

    int col;
    cout << "Enter number of Columns: ";
    cin >> col;

    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << "The matrix is: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout <<endl;
    }

    cout << "Index of the key is: ";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(key == arr[i][j]){
                cout << i << "," << j << endl;
            }
        }
    }
}