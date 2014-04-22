#include "../include/CTree.hpp"

CTree::CTree (sf::Sprite *pSprite, sf::Vector2f fPos, sf::Vector2i iSize)
{
    m_pSprite = nullptr;
    m_pSprite = pSprite;
    m_fPos = fPos;
    m_iSize = iSize;
    m_pSprite->setPosition (m_fPos);
    m_pSprite->setTextureRect (sf::IntRect (0, 0, m_iSize.x, m_iSize.y));
}

CTree::~CTree ()
{
    m_pSprite = nullptr;
}

bool CTree::checkCollision (sf::Vector2f fPos, sf::Vector2i iSize)
{
    return ((fPos.x + static_cast <float> (iSize.x / 2) > m_fPos.x) &&
            (fPos.y + static_cast <float> (iSize.y / 2) > m_fPos.y) &&
            (fPos.x - static_cast <float> (iSize.x / 2) < m_fPos.x + static_cast<float> (m_iSize.x)) &&
            (fPos.y - static_cast <float> (iSize.y / 2) < m_fPos.y + static_cast<float> (m_iSize.y)));
}

/*sf::Sprite* CTree::getSprite ()
{
    return m_pSprite;
}*/
