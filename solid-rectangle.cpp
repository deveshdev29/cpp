#include <iostream>
using namespace std;

int main(){

    int rows;
    cout << "Number of Rows????? ";
    cin >> rows;

    int columns;
    cout << "Number of Columns????? ";
    cin >> columns;

    for(int i  = 0; i <  rows;i++){
        for(int j = 0;j < columns;j++){
            cout << "*";
        }
        cout << endl;
    }
}