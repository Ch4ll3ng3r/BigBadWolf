#include "../include/CCreature.hpp"

CCreature::CCreature (sf::Sprite *pSprite, sf::Vector2f fPos)
{
    m_pSprite = nullptr;
    m_pSprite = pSprite;
    m_strName = "Creature";
    m_fPos = fPos;
    m_fOldPos = sf::Vector2f (0.f, 0.f);
    m_iSize = sf::Vector2i (30, 30);
    m_fDirection = 0.f;
    m_fVelocity = 0.35f;
    m_pSprite->setOrigin (static_cast<sf::Vector2f> (m_iSize / 2));
    m_pSprite->setPosition (m_fPos);
    m_pSprite->setTextureRect (sf::IntRect (0, 0, m_iSize.x, m_iSize.y));
}

CCreature::~CCreature ()
{
    m_pSprite = nullptr;
}

void CCreature::move (unsigned int uiElapsedTime)
{
    m_fOldPos = m_fPos;
    if (m_fDirection == 0.f)
        m_fPos.y -= m_fVelocity * uiElapsedTime;
    else if (m_fDirection == 90.f)
        m_fPos.x += m_fVelocity * uiElapsedTime;
    else if (m_fDirection == 180.f)
        m_fPos.y += m_fVelocity * uiElapsedTime;
    else if (m_fDirection == 270.f)
        m_fPos.x -= m_fVelocity * uiElapsedTime;
}

void CCreature::setDirection (float fDirection)
{
    m_fDirection = fDirection;
    m_pSprite->setRotation (m_fDirection);
}

void CCreature::confirmMove ()
{
    m_pSprite->setPosition (m_fPos);
}

void CCreature::denyMove ()
{
    m_fPos = m_fOldPos;
}

sf::Vector2i CCreature::getSize ()
{
    return m_iSize;
}

sf::Vector2f CCreature::getPos ()
{
    return m_fPos;
}

bool CCreature::checkCollision (sf::Vector2f fPos, sf::Vector2i iSize)
{
    return ((fPos.x + static_cast <float> (iSize.x / 2) > m_fPos.x - static_cast<float> (m_iSize.x / 2)) &&
            (fPos.y + static_cast <float> (iSize.y / 2) > m_fPos.y - static_cast<float> (m_iSize.y / 2)) &&
            (fPos.x - static_cast <float> (iSize.x / 2) < m_fPos.x + static_cast<float> (m_iSize.x / 2)) &&
            (fPos.y - static_cast <float> (iSize.y / 2) < m_fPos.y + static_cast<float> (m_iSize.y / 2)));
}
