#include "TAnimal.h"



TAnimal::TAnimal()
        : Name()
        , Age(0)
        , alive(1)
        , isPair(0)
{


}

TAnimal::TAnimal(const std::string & name)
        : Name(name)
        , Age(0)
        , alive(1)
        , isPair(0)
{


}

std::string TAnimal::GetName() const
{return Name; }

float TAnimal::Years() const
{return Age;}

bool TAnimal::living() const
{return alive; }

void TAnimal::killHim(bool l)
{alive = l; }

void TAnimal::increaseAge(float y)
{Age +=y; }

void TAnimal::setType(int l)
{type = l; }

bool TAnimal::vPare() const
{return isPair; }

void TAnimal::createPara(bool i)
{isPair = i; }

int TAnimal::getType() const
{return type; }