#include <thread>
#include "zooList.h"


int switchAnimals(TZoo & zoo1,int i1, TZoo & zoo2, int i2){
    zoo1.AddNewAnimal(&zoo2[i2]);
    zoo2.AddNewAnimal(&zoo1[i1]);
    zoo1.deleteByIndex(i1);
    zoo2.deleteByIndex(i2);
	return 0;
}

int main() {
    TZoo myZoo_first(288);
    TZoo myZoo_second(288);
    TAnimal *tiger = new TTigris("pasha");
    TAnimal *second_tiger = new TTigris("petya");
    TAnimal *slon = new TElephas("vasya");
    TAnimal * gip = new THippopotamus("vera");
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










        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    system("pause");
}