#ifndef CWOLF_HPP_INCLUDED
#define CWOLF_HPP_INCLUDED

#include "CCreature.hpp"


class CWolf : public CCreature
{
    public:
        CWolf (sf::Sprite *pSprite, sf::Vector2f fPos);
};

#endif // CWOLF_HPP_INCLUDED
