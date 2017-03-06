#import <iostream>

class PERSON {

private:

    std::string Name;
    int Age;

public:

    PERSON();
    PERSON(const std::string & a, const int & b);

    virtual ~PERSON();

    void setName(const std::string & n);

    void setAge(const int & n);

};

