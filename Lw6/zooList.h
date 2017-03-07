#include <iostream>
#include "TZoo.h"


class TArtuidactyla
        : public TAnimal {
public:
    TArtuidactyla(const std::string &name) : TAnimal(name) {};

};

class TProboscidea
        : public TAnimal {
public:
    TProboscidea(const std::string &name) : TAnimal(name) {};
};

class TCarnivora
        : public TAnimal {
public:
    TCarnivora(const std::string &name) : TAnimal(name) {};
};

class TGiraffa
        : public TArtuidactyla {
public:
    TGiraffa(const std::string &name)
            : TArtuidactyla(name) {
        TAnimal::setType(0);
    };
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 10.f && ((int) time) % 24 <= 11.f)
            std::cout << GetName() << " is eating" << std::endl;
        else if (TAnimal::Years() > 2) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        }
        else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        return TAnimal::Years() < 2;
    }
};

class THippopotamus
        : public TArtuidactyla {
public:
    THippopotamus(const std::string &name)
            : TArtuidactyla(name) { TAnimal::setType(1); }
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 10.f && ((int) time) % 24 <= 11.f)
            std::cout << GetName() << " is lauphing" << std::endl;
        else if (TAnimal::Years() > 6) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        } else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        return TAnimal::Years() < 3;
    }
};

class TElephas
        : public TProboscidea {
public:
    TElephas(const std::string &name)
            : TProboscidea(name) { TAnimal::setType(2); }
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 10.f && ((int) time) % 24 <= 11.f)
            std::cout << GetName() << " is taking shower" << std::endl;
        else if (TAnimal::Years() > 5) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        }
        else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        return TAnimal::Years() < 2;
    }
};

class TLoxodonta
        : public TProboscidea {
public:
    TLoxodonta(const std::string &name)
            : TProboscidea(name) { TAnimal::setType(3); };
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 5.f && ((int) time) % 24 <= 11.f)
            std::cout << GetName() << " is swimming" << std::endl;
        else if (TAnimal::Years() > 7) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        }
        else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        return TAnimal::Years() < 3;
    }
};

class TLeo
        : public TCarnivora {
public:
    TLeo(const std::string &name)
            : TCarnivora(name) { TAnimal::setType(4); };
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 4.f && ((int) time) % 24 <= 10.f)
            std::cout << GetName() << " is fighting" << std::endl;
        else if (TAnimal::Years() > 5) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        }
        else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        return TAnimal::Years() < 2;
    }
};

class TTigris
        : public TCarnivora {
public:
    bool alive = 1;
    TTigris(const std::string &name)
            : TCarnivora(name) { TAnimal::setType(5); };
    virtual void Live(float time) override {
        if (!TAnimal::living()) return;
        if (((int) time) % 24 >= 8.f && ((int) time) % 24 <= 9.f)
            std::cout << GetName() << " is playing" << std::endl;
        else if (TAnimal::Years() > 4) {
            TAnimal::killHim(0);
            std::cout << GetName() << " is dead!" << std::endl;
        } else
            std::cout << GetName() << " is sleeping" << std::endl;
    }
    virtual bool isReady() override {
        float t;
        t = TAnimal::Years();
        return TAnimal::Years() > 2;
    }

};
