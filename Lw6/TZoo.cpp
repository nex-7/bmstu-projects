#include "TZoo.h"
#include "zooList.h"
#include <iostream>

TZoo::TZoo(size_t capacity)
        : Capacity(capacity), NumAnimals(0), Time(0) {
    Animals = new TPtrAnimal[Capacity];
    memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}

bool TZoo::AddNewAnimal(TAnimal **newAnimal) {
    // Проверяем корректность входного параметра
    if (newAnimal == nullptr)
        return false;

    // Зоопарк полон, нельзя добавить нового зверя
    if (NumAnimals == Capacity)
        return false;

    // Добавляем зверя в массив
    Animals[NumAnimals] = *newAnimal;

    // Забираем зверя у старого владельца, чтобы не удалить зверя дважды
    //*newAnimal = nullptr;

    // Увеличиваем счетчик
    ++NumAnimals;

    return true;
}


void TZoo::Work() {
    int t = 0;
    for (size_t i = 0; i < NumAnimals; ++i) {
        if (Animals[i + t] != nullptr && Animals[i + t] != NULL)
            // Демонстрация работы динамического полиморфизма
            if (!Animals[i + t]->living()) {
                deleteByIndex(i + t);
                t -= 1;
            } else {
                Animals[i + t]->increaseAge(0.3);
                Animals[i + t]->Live(Time);
            }
    }

    std::string tmp;

    int a = 0;
    int b = 0;

    for (size_t i = 0; i < NumAnimals; ++i) {
        a = Animals[i]->isReady();
        b = !(Animals[i]->vPare());
        if (Animals[i]->isReady() && !(Animals[i]->vPare())) {

            for (size_t x = i + 1; x < NumAnimals; ++x) {

                if (Animals[i]->getType() == Animals[x]->getType()) {

                    if (Animals[x]->isReady() && !(Animals[x]->vPare() && !(Animals[i]->vPare()))) {

                        std::cout << "Родилось новое животное " << Animals[i]->getType() << "! Имя: ";
                        std::cin >> tmp;

                        Animals[x]->createPara(1);
                        Animals[i]->createPara(1);

                        TAnimal *tmp1;
                        int t = Animals[i]->getType();
                        switch (t) {
                            case 0:
                                tmp1 = new TGiraffa(tmp);
                                break;
                            case 1:
                                tmp1 = new THippopotamus(tmp);
                                break;
                            case 2:
                                tmp1 = new TElephas(tmp);
                                break;
                            case 3:
                                tmp1 = new TLoxodonta(tmp);
                                break;
                            case 4:
                                tmp1 = new TLeo(tmp);
                                break;
                            case 5:
                                tmp1 = new TTigris(tmp);
                                break;
                        }
                        AddNewAnimal(&tmp1);
                    }}}}}
    Time += STEP;
}


TZoo::~TZoo() {
    for (size_t i = 0; i < NumAnimals; ++i) {
        delete Animals[i];
    }
    delete[] Animals;
}

TAnimal *TZoo::operator[](int i) const {

    return Animals[i];
}

TAnimal *&TZoo::operator[](int i) {
    return Animals[i];
}

void TZoo::deleteByIndex(int i) {
    if (NumAnimals > 1) {
        for (int x = i + 1; x < NumAnimals; x++) {
            Animals[x - 1] = Animals[x];
            Animals[x] = nullptr;
        }
        NumAnimals -= 1;
    } else {
        Animals[0] = NULL;
        NumAnimals = 0;
    }
}