#ifndef CTREE_HPP_INCLUDED
#define CTREE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class CTree
{
    public:
        CTree (sf::Sprite *pSprite, sf::Vector2f fPos, sf::Vector2i iSize);
        ~CTree ();
        bool checkCollision (sf::Vector2f fPos, sf::Vector2i iSize);
        sf::Sprite* getSprite ();

    private:
        sf::Sprite *m_pSprite;
        sf::Vector2f m_fPos;
        sf::Vector2i m_iSize;
};

#endif // CTREE_HPP_INCLUDED
