#ifndef SMART_POINTER_PROJECT_PERSON_H
#define SMART_POINTER_PROJECT_PERSON_H
#include "license.h"
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Person {
    string name;
    unsigned int wealth;
    map<string,unique_ptr<License> > licenses;
public:
    Person(string name, unsigned int wealth);
    virtual ~Person();
    void work(string guild);
    virtual void work(unsigned int) = 0;
    void increase_wealth(unsigned int i);
    string get_name() const;
    bool pay_fee(unsigned int i);
    void receive_license(unique_ptr<License> l);
    void transfer_license(string l, shared_ptr<Person> p);
    bool eligible(string l) const;
    virtual ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const Person& p);

class Worker: public Person{
public:
    Worker(string, unsigned  int);
    void work(unsigned  int i);
    ostream& print(ostream& o) const;
};

class Superworker: public Person{
    unsigned int fee;
public:
    Superworker(unsigned int fee, string, unsigned int);
    void work(unsigned int i);
    ostream& print(ostream& o) const;
};

#endif //SMART_POINTER_PROJECT_PERSON_H
