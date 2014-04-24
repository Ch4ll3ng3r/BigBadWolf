#ifndef CCREATURE_HPP_INCLUDED
#define CCREATURE_HPP_INCLUDED

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

class CCreature
{
    public:
        CCreature (sf::Sprite *pSprite, sf::Vector2f fPos);
        virtual ~CCreature ();
        void move (unsigned int uiElapsedTime);
        void confirmMove ();
        void denyMove ();
        void setDirection (float fDirection);
        sf::Vector2i getSize ();
        sf::Vector2f getPos ();
        bool checkCollision (sf::Vector2f fPos, sf::Vector2i iSize);
        string getName ();

    protected:
        string m_strName;
        sf::Sprite *m_pSprite;
        sf::Vector2f m_fPos;
        sf::Vector2f m_fOldPos;
        sf::Vector2i m_iSize;
        float m_fDirection;
        float m_fVelocity;
};

#endif // CCREATURE_HPP_INCLUDED
