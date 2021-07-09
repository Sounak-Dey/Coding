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


void swap(Person *p1, Person *p2) // same as java
{
    p1 = new Person();
    int age = p1->age;
    p1->age = p2->age;
    p2->age = age;

    p2 = new Person();
    string name = p1->name;
    p1->name = p2->name;
    p2->name = name;

    delete p1;
    delete p2;
}

//output
// p5[50] says hi
// p7[70] says hi
// p5[50] says hi
// p7[0] says hi

// as when we do p1 = new Person()
// a p1 is allocated new memory that references to a new object 
// where all values are initialised to 0

int main()
{


    Person *p5 = new Person();   // creates a new reference everytime
    p5->name = "p5";
    p5->age = 50;

    Person *p7 = new Person();   // creates a new reference everytime
    p7->name = "p7";
    p7->age = 70;

    

    p5->saysHi();
    p7->saysHi();
    swap(p5, p7);
    p5->saysHi();
    p7->saysHi();


    delete p5;
    delete p7;
}


