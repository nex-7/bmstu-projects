#include "PERSON.h"


PERSON::PERSON()
        :Name(""), Age(0) {
}

PERSON::PERSON(const std::string & a, const int & b) {
    Name = a;
    Age = b;
}

PERSON::~PERSON(){

    Age = 0;

    Name.clear();

}

void PERSON::setName(const std::string & n){

    Name = n;

}

void PERSON::setAge(const int & n){

    Age = n;

}