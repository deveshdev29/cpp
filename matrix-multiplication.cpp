#include <iostream>
using namespace std;


int main(){

    cout << "Enter Rows and Columns of first matrix" << endl;
    int row1;
    cin >> row1;
    int col1;
    cin >> col1;
    int arr1[row1][col1];

    cout << "Enter First Matrix" << endl;
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col1; j++){
            cin >> arr1[i][j];
        }
    }

    cout << "Enter Rows and Columns of second matrix" << endl;
    int row2;
    cin >> row2;
    int col2;
    cin >> col2;
    int arr2[row2][col2];

    cout << "Enter Second matrix" << endl;
    for(int i = 0; i < row2; i++){
        for(int j = 0; j < col2; j++){
            cin >> arr2[i][j];
        }
    }

    int multi[row1][col2];    
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            multi[i][j] = 0;
        }
    }


    if(col1 == row2){
       
        for(int i = 0; i < row1; i++){
            for(int j = 0; j < col2; j++){
                for(int k = 0; k < col1; k++){
                    multi[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
       }

    }else{
        cout << "Matrix could not multiplied" << endl;
        return 0;
    }

    cout << "Matrix Multiplication" << endl;
    for(int i = 0; i < row1; i++){
        for(int j = 0; j < col2; j++){
            cout << multi[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}