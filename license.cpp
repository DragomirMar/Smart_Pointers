#include<iostream>
#include "license.h"
using namespace std;

License::License(string name, unsigned int salary): name{name}, salary{salary}{
    if(name.empty())
        throw runtime_error("No name!");
    if(salary<=0)
        throw runtime_error("No salary!");
}

string License::get_guildname() const{ return name;}

unsigned int License::get_salary() const{ return salary;}

bool License::valid() const{
    if(counter>4 || counter<0)
        return false;
    return true;
}

bool License::use(){
    if(valid()){
        ++counter;
        return true;
    }
    return false;
}

ostream& License::print(ostream& o) const{
    o<< "[License for "<< name << ", Salary: "<< salary << ", Used: " << counter <<"]";
    return o;
}

ostream& operator<<(ostream& o, const License& l){
    return l.print(o);
}