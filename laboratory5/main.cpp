#include <iostream>
#include "STUDENT.h"

int main() {
    STUDENT a("Lyoha",18,"Alg 93", 5);

    a.setName("Alyosha");
    a.setAge(27);
    a.chooseLesson("cool");
    a.chooseMark(2);
    a.showMark();

}