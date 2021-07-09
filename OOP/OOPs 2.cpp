#include<iostream>
#include<string>
using namespace std;

class Person
{
    public:

    int age;
    string name;

    void saysHi()
    {
        cout<<name<<"["<<age<<"] says hi"<<endl;
    }

};


void swap(Person p1, Person p2) // wont swap you need to pass as reference, but swaps in java
{                                   // because we are referencing to the same instance in java
    int age = p1.age;               // but for C++ it creates new instance as well
    p1.age = p2.age;
    p2.age = age;

    string name = p1.name;
    p1.name = p2.name;
    p2.name = name;
}

int main()
{
    Person p1, p2; // creates new object/instance every time

    p1.age = 10;
    p1.name = "p1";

    p2.age = 20;
    p2.name = "p2";


    p1.saysHi();
    p2.saysHi();
    swap(p1, p2);
    p1.saysHi();
    p2.saysHi();

    return 0;
}
