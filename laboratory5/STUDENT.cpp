//
// Created by ilja on 06.03.17.
//

#include "STUDENT.h"


STUDENT::STUDENT()
        : PERSON(), mark(0),lesson(""){
};

STUDENT::STUDENT(const std::string & a, const int & b,const std::string & c, const int & d )
        :PERSON(a,b), mark(d), lesson(c){
};

STUDENT::~STUDENT() {
    lesson.clear();
    mark = 0;
}

void STUDENT::chooseLesson(std::string l) {
    lesson = l;
    return;
}

void STUDENT::chooseMark(int l) {
    mark = l;
    return;
}

void STUDENT::showMark(){

    if (mark==2){
        std::cout << "Very BAD mark!\n";
    } else {
        std::cout << "Goooood JOB!\n";
    }
}
