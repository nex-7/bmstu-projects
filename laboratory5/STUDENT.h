#include "PERSON.h"
#include "iostream"

class STUDENT: public PERSON {

    std::string lesson;
    int mark;
public:
    STUDENT();
    STUDENT(const std::string & a, const int & b,const std::string & c, const int & d );
    ~STUDENT();
    void chooseLesson(std::string l);
    void chooseMark(int l);
    void showMark();
};
