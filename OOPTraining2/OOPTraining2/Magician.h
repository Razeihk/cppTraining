#pragma once

#include "Character.h"



class Magician :
    public Character
{
public:
    void Fireball() const;
    void IceBall() const;

private:
    int m_Mana = 100;
};

