#ifndef SMART_POINTER_PROJECT_LICENSE_H
#define SMART_POINTER_PROJECT_LICENSE_H
#include<iostream>
#include<string>
using namespace std;

class License {
    string name;
    unsigned int salary;
    unsigned int counter;
public:
    License(string name, unsigned int salary);
    string get_guildname() const;
    unsigned int get_salary() const;
    bool valid() const;
    bool use();
    ostream& print(ostream& o) const;
};
ostream& operator<<(ostream& o, const License& l);

#endif //SMART_POINTER_PROJECT_LICENSE_H
