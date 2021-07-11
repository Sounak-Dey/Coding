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

int main()
{
    Person p1, p2; // everytime a new instance is created

    p1.age = 10;
    p1.name = "p1";
    p1.saysHi();

    p2.age = 20;
    p2.name = "p2";
    p2.saysHi();

    Person p3 = p1; //only values copied new instance created
    p3.age = 30;     // p1.age not changed
    p1.saysHi();
    p3.saysHi();

    Person *p4 = &p1;   //referenced copied no new instance created
    p4->age = 30;        // p1.age also changes
    p1.saysHi();
    p4->saysHi();

    Person *p5 = new Person();  // everytime new reference is created
    p5->name = "p5";
    p5->age = 50;
    p5->saysHi();

    Person *p6 = p5;    //referenced copied no new instance created
    p6->age = 60;       //p5->age also changes
    p6->saysHi();
    p5->saysHi();

    delete p5;

}