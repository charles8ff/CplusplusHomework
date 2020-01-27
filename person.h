#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
private:
    int age;
    string name;
    string phoneNumber;

public:
    Person();
    int getAge() const;
    void setAge(int value);
    string getName() const;
    void setName(const string &value);
    string getPhoneNumber() const;
    void setPhoneNumber(const string &value);
    void print ()const;
};

#endif // PERSON_H
