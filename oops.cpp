#include <iostream>
using namespace std;

class Student{
public:
    string name;
    int age;
    bool gender;


    // Default Constructor
    Student(){
        cout << "Default constructor" << endl;
    }

    // parameter constructor
    Student(string s, int a, bool g){
        name = s;
        age = a;
        gender = g;
    }


    void printInfo(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

int main(){

    //  object of the class Student
    Student obj("dev", 20, 1);
    obj.printInfo();

    Student b;

    return 0;
}