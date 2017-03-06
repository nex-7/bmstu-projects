#pragma once

#include <string>


class TAnimal {
    std::string Name;
    float Age;
    int type;
    bool isPair;
    bool alive;

public:

    TAnimal();
    TAnimal(const std::string &name);
    virtual ~TAnimal() = default;
    virtual void Live(float time) = 0;
    std::string GetName() const;
    float Years() const;
    bool living() const;
    void killHim(bool l);
    virtual void setType(int l);
    int getType() const;
    void increaseAge(float y);
    bool vPare() const;
    void createPara(bool i);
    virtual bool isReady() = 0;

};
