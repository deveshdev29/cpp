#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> nums;

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;
        nums.push_back(value);
    }

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    nums.push_back(10);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}