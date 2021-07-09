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


void swap(Person p1, Person p2) //won't swap in both C++ and java
{
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    Person p1, p2; // creates new object/ instance every time

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
