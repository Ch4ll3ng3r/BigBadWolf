#ifndef CLEVEL_HPP_INCLUDED
#define CLEVEL_HPP_INCLUDED

#include "CTree.hpp"
#include <vector>
#include <list>
#include "SafeDelete.hpp"
#include <stdlib.h>

using namespace std;

class CLevel
{
    public:
        CLevel (list<sf::Sprite*> *lpSprites, sf::Texture &rTexture, sf::Vector2i iSize);
        ~CLevel ();
        bool checkCollision (sf::Vector2f fPos, sf::Vector2i iSize);

    private:
        vector<CTree*> m_vpTrees;
        sf::Vector2i m_iSize;
};

#endif // CLEVEL_HPP_INCLUDED
