#include <iostream>
using namespace std;

int main(){

    int n;
    cout << "Enter size of the matrix: ";
    cin >> n;

    int row = n;
    int col = n;

    int arr[row][col];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> arr[i][j];
        }
    }

    cout << "Matrix entered is " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Transpose of the matrix: " << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}