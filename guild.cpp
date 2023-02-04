#include "guild.h"
#include "person.h"
#include<iostream>
#include <vector>
#include <map>
using namespace std;

Guild::Guild(string name, unsigned fee, unsigned sal, const vector<shared_ptr<Person>>& members = {})
: name{name}, fee{fee}, salary{sal}{
    if(name.empty())
        throw runtime_error("No name of Guild");
    if(salary<0 || fee<0)
        throw runtime_error("Salary or fee below 0!");

    for(auto i= members.begin(); i != members.end(); ++i){
        for(auto j = members.begin()+1; j<= members.end(); ++j){
            if(j==i)
                throw runtime_error("Same person is multiple times listed!");
        }
    }
}

bool Guild::add_member(shared_ptr<Person> p){
   /* for(auto i = members.begin(); i != members.end(); ++i){
        if(i->second == p)
            return false;
    }*/
   if(members.find(p->get_name()) != members.end()){ // if the iterator finds p before reaching the end means that the element is already in the map.
       return false;}
    members.insert(make_pair(p->get_name(), p));
    return true;
    //option 2//members.insert(pair<string,shared_ptr<Person>>{p->get_name(), p} );
}

bool Guild::remove_member(string n){
    if(members.find(n) != members.end()) {
        members.erase(n);
        return true;
    }
    return false;
}

void Guild::grant_license(string n){
    if(!(members.count(n) && members[n]->pay_fee(fee))){

        unique_ptr<License> ptr (new License(name, salary));
        members[n]->receive_license(move(ptr));
        return;}
    throw runtime_error("Cannot grant license");
}

bool Guild::offer_job(shared_ptr<Person> p) const{
    if(members.find(p->get_name()) != members.end()){
        p->work(salary*2);
        return true;
    }
    if(p->eligible(name)) {
        p->work(salary);
        return true;
    }
    return false;
}

ostream& Guild::print(ostream& o) const{
    o<<"["<< name << ", License fee: "<< fee << ", Job salary: "<< salary<<", {";
    bool first{true};
    for(const auto& i: members){
        if(first)
            first=false;
        else
            o<<", ";
        o<< i.second->get_name();
    }
    o<<"}]";
    return o;
}

ostream& operator<<(ostream& o, const Guild& g){
    return g.print(o);
}