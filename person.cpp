#include "person.h"
#include <iostream>
using namespace std;


string Person::getName() const
{
    return name;
}

void Person::setName(const string &value)
{
    name = value;
}

int Person::getAge() const
{
    return age;
}

void Person::setAge(int value)
{
    if(value<0){
        cout<<"wrong";
    }
    age = value;
}

string Person::getPhoneNumber() const
{
    return phoneNumber;
}

void Person::setPhoneNumber(const string &value)
{
    if(phoneNumber.size()==9) phoneNumber = value;
    else cout<<"eres imbecil";
}
void Person::print()  const
{
    cout<<getName()<<"\t"<<getPhoneNumber()<<"\t"<<getAge();
}

Person::Person()
{

}
