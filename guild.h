#ifndef SMART_POINTER_PROJECT_GUILD_H
#define SMART_POINTER_PROJECT_GUILD_H
#include<iostream>
#include "person.h"
#include <vector>
using namespace std;

class Guild {
    string name;
    unsigned int fee;
    unsigned int salary;
    map<string,shared_ptr<Person>> members;
public:
    Guild(string name, unsigned fee, unsigned sal, const vector<shared_ptr<Person> >& members);
    bool add_member(shared_ptr<Person> p);
    bool remove_member(string n);
    void grant_license(string n);
    bool offer_job(shared_ptr<Person> p) const;
    ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const Guild& g);

#endif //SMART_POINTER_PROJECT_GUILD_H
