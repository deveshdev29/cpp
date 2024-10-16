#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> ages;

    ages["dev"] = 20;

    for(const auto &pair : ages){
        cout << "Name is " << pair.first << " and age is " << pair.second << endl;
    }

    string name;
    cin >> name;

    if(ages.find(name) != ages.end()){
        cout << name << " age is " << ages[name] << endl;
    }else{
        cout << name << " not found" << endl;
    }

    return 0;
}