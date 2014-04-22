#include "../include/CLevel.hpp"

CLevel::CLevel (list<sf::Sprite*> *lpSprites, sf::Texture &rTexture, sf::Vector2i iSize)
{
    m_iSize = iSize;
    int iNbTrees = rand () % 6 + 5;
    for (int i = 0; i < iNbTrees; i++)
    {
        sf::Sprite *pSprite = nullptr;
        pSprite = new sf::Sprite (rTexture);
        CTree *pTree = nullptr;
        pTree = new CTree (pSprite,
                           sf::Vector2f (rand () % m_iSize.x, rand () % m_iSize.y),
                           sf::Vector2i ((rand () % 20 + 1) * 30, (rand () % 20 + 1) * 30));
        lpSprites->push_back (pSprite);
        m_vpTrees.push_back (pTree);
        pTree = nullptr;
        pSprite = nullptr;
    }
}

CLevel::~CLevel ()
{
    vector<CTree*>::iterator i;
    for (i = m_vpTrees.begin (); i != m_vpTrees.end (); i++)
    {
        SAFE_DELETE (*i);
    }
    m_vpTrees.clear ();
}

bool CLevel::checkCollision (sf::Vector2f fPos, sf::Vector2i iSize)
{
    bool bCollided = false;
    if ((fPos.x - static_cast<float> (iSize.x / 2) < 0.f) ||
        (fPos.y - static_cast<float> (iSize.y / 2) < 0.f) ||
        (fPos.x + static_cast<float> (iSize.x / 2) > static_cast<float> (m_iSize.x)) ||
        (fPos.y + static_cast<float> (iSize.y / 2) > static_cast<float> (m_iSize.y)))
        bCollided = true;
    vector<CTree*>::iterator i;
    for (i = m_vpTrees.begin (); i != m_vpTrees.end (); i++)
    {
        if ((*i)->checkCollision (fPos, iSize))
            bCollided = true;
    }
    return bCollided;
}
