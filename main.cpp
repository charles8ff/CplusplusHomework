#include <iostream>
#include <string>
#include <person.h>
#include <set>
#include <functional>

using namespace std;

void addListin(Person niu,set<Person>listin)
{
    listin.insert(niu);
}
void forEach(set<Person>const &listin,
             function<void(Person)> const & op)
{
    for(auto elem:listin){
        op(elem);
    }
}
Person find(set<Person>const &listin,
            function<bool(Person)>const & cond)
{
    for(auto elem:listin){
        if(cond(elem)) return elem;
    }
    return Person();
}
set<Person> filter(set<Person>const &listin,
                   function<bool(Person)>const & cond)
{
    set<Person>result;
    for(auto elem:listin){
        if(cond(elem))  result.insert(elem);
    }
    return result;
}
void printListin(set<Person>const &listin){
    forEach(listin,[=](Person elem){elem.print();});
}

int main()
{
    set<Person>daListin;
    Person p1;
    p1.setAge(20);
    p1.setName("Carlos Fisac");
    p1.setPhoneNumber("622497567");
    Person p2;
    p2.setAge(19);
    p2.setName("Rayitas Rivera");
    p2.setPhoneNumber("212121212");
    Person p3;
    p3.setAge(10);
    p3.setName("Avalero Gei");
    p3.setPhoneNumber("555555555");

    addListin(p1,daListin);
    addListin(p2,daListin);
    addListin(p3,daListin);
    //buscar por nombre
    string target{"Carlos Fisac"};
    Person encontrada= find(daListin,[=](Person elem){
        return (elem.getName()==target);
    });
    //filtrar por edad y listar




    return 0;
}
