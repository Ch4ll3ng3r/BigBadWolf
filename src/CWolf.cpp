#include "../include/CWolf.hpp"

CWolf::CWolf (sf::Sprite *pSprite, sf::Vector2f fPos)
: CCreature (pSprite, fPos)
{
    m_strName = "Wolf";
}
