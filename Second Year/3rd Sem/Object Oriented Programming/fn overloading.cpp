
#include<iostream>
using namespace std;

class Animal
{
public:
    virtual void eat()
    {
        cout<< "Animal is eating"<<endl;
    }

};
class Dog:public Animal
{
public:
    virtual void eat()
    {
        cout<< "dog is eating"<<endl;
    }

};
class Cat:public Animal
{
public:
    void eat()
    {
        cout<< "cat is eating"<<endl;
    }

};
int main()
{
    Animal *a;
    Animal a1;
    //Dog *d;
    //d=&a1;
    //d->eat();
    a=&a1;
    a->eat();
    Dog d;
    a=&d;
    a->eat();
    Cat c;
    a=&c;
    a->eat();
}
