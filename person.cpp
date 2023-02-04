#include "person.h"

Person::Person(string name, unsigned int wealth = 0): name{name}, wealth{wealth}{
    if(name.empty())
        throw runtime_error("This person has no name!");
}
Person::~Person() = default;

void Person::work(string guild){
    if(!(licenses.find(guild) != licenses.end()) && !(licenses[guild]->valid()))
        throw runtime_error ("No license or the license is not able to be used!");

    licenses[guild]->use();
    work(licenses[guild]->get_salary());
}

void Person::work(unsigned int){}

void Person::increase_wealth(unsigned int i){
    wealth +=i;
}

string Person::get_name() const{ return name;}

bool Person::pay_fee(unsigned int i){
    if(wealth<i || i==0)
        return false;
    else{
        wealth -= i;
        return true;}
}

void Person::receive_license(unique_ptr<License> l){
   /* for(auto i = licenses.begin(); i != licenses.end(); ++i){
        if(i->second == l)
            licenses.erase(l->get_guildname());
    }*/
   if(eligible(l->get_guildname()))
       licenses.erase(l->get_guildname());

    licenses.insert(make_pair(l->get_guildname(), move(l)));
}

void Person::transfer_license(string l, shared_ptr<Person> p){
   // p->licenses.insert(make_pair(l, licenses[l]));
   if(!(licenses.find(l) != licenses.end()))
        throw runtime_error("No such license found");
   p->receive_license(move(licenses[l]));
   licenses.erase(l);
}

bool Person::eligible(string l) const{
    if(licenses.count(l) && licenses.at(l)->valid())
        return true;
    return false;
}

ostream& Person::print(ostream& o) const{
    o<< name << ", " << wealth << " Coins { ";
    bool first{true};
    for(const auto& i: licenses){
        if(first)
            first=false;
        else
            o<<", ";
        i.second->get_guildname();
    }
    o<<"}]";
    return o;
}

ostream& operator<<(ostream& o, const Person& p){
    return p.print(o);
}


Worker::Worker(string name, unsigned  int wealth= 0)
: Person(name, wealth){}

void Worker::work(unsigned  int i){
    increase_wealth(i);
}
ostream& Worker::print(ostream& o) const{
    o<<"[Worker ";
    return Person::print(o);
}



Superworker::Superworker(unsigned int fee, string name, unsigned int wealth= 0)
: fee{fee},Person(name, wealth){}

void Superworker::work(unsigned int i){
    increase_wealth(i+fee);
}
ostream& Superworker::print(ostream& o) const{
    o<<"[Superworker ";
    return Person::print(o);
}