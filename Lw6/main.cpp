#include <thread>
#include "zooList.h"

enum TAnimalType {
    TGiraffaType = 0
    , THippopotamusType
    , TElephasType
    , TLoxodontaType
    , TLeoType
    , TTigrisType
};

int switchAnimals(TZoo & zoo1,int i1, TZoo & zoo2, int i2){
    zoo1.AddNewAnimal(&zoo2[i2]);
    zoo2.AddNewAnimal(&zoo1[i1]);
    zoo1.deleteByIndex(i1);
    zoo2.deleteByIndex(i2);
	return 0;
}

TAnimal * createAnimal(TAnimalType type, std::string name = "Name")
{
    if (type == TGiraffaType) {
        return new TGiraffa(name);
    }
    else if (type == THippopotamusType) {
        return new THippopotamus(name);
    }
    else if (type == TElephasType) {
        return new TElephas(name);
    }
    else if (type == TLoxodontaType) {
        return new TLoxodonta(name);
    }
    else if (type == TLeoType) {
        return new TLeo(name);
    }
    else if (type == TTigrisType) {
        return new TTigris(name);
    }
    else {
        return nullptr;
    }
}

int main() {
    TZoo myZoo_first(288);
    TZoo myZoo_second(288);
    TAnimal *tiger = createAnimal(TTigrisType, "pasha");
    TAnimal *second_tiger = createAnimal(TTigrisType, "petya");
    TAnimal *slon = createAnimal(TElephasType, "vasya");
    TAnimal * gip = createAnimal(TGiraffaType, "vera");
    if (!myZoo_first.AddNewAnimal(&tiger))
        delete tiger;
    if (!myZoo_first.AddNewAnimal(&second_tiger))
        delete second_tiger;
    if (!myZoo_first.AddNewAnimal(&slon))
        delete slon;
    if (!myZoo_second.AddNewAnimal(&gip))
        delete gip;

    for (size_t i = 0; i < 100; ++i) 
	{
        myZoo_first.Work();
        myZoo_second.Work();
        if (i == 5) {
            switchAnimals(myZoo_first,1,myZoo_second,0);
        }
        std::cout << std::endl;

        if (i % 10 == 0) {
            std::string name;
            std::cout << "Введите имя: ";
            std::cin >> name;
            TAnimal * animal = createAnimal(TAnimalType(rand() % 6), name);
            if (!myZoo_first.AddNewAnimal(&animal))
                delete animal;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("pause");
}
