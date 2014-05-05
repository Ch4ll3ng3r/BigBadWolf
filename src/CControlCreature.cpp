#include "../include/CControlCreature.hpp"

CControlCreature::CControlCreature (CCreature *pCreature, CCreature *pEnemy, CLevel *pLevel)
{
    m_pCreature = nullptr;
    m_pEnemy = nullptr;
    m_pLevel = nullptr;
    m_pCreature = pCreature;
    m_pEnemy = pEnemy;
    m_pLevel = pLevel;
    m_uiElapsedTime = 0;
    m_dCurDistance = 0.;
    m_dOldDistance = 0.;
    m_fBestDirection = 0.f;
}

CControlCreature::~CControlCreature()
{
    m_pCreature = nullptr;
    m_pEnemy = nullptr;
    m_pLevel = nullptr;
}

void CControlCreature::update (unsigned int uiElapsedTime)
{
    m_uiElapsedTime = uiElapsedTime;
    m_dOldDistance = m_dCurDistance;
    calculateDistance ();
    if (isDirectionChangeNecessary ())
    {
        calculatePossibleMoves ();
        chooseBestMove ();
    }
    m_pCreature->move (m_uiElapsedTime);
}

void CControlCreature::calculateDistance ()
{
    sf::Vector2f fPosSelf = m_pCreature->getPos ();
    sf::Vector2f fPosEnemy = m_pEnemy->getPos ();
    m_dCurDistance = sqrt (pow (static_cast<double> (fPosSelf.x - fPosEnemy.x), 2.0) +
                           pow (static_cast<double> (fPosSelf.y - fPosEnemy.y), 2.0));
}

void CControlCreature::chooseBestMove ()
{
    if (m_fBestDirection != -1.f)
        m_pCreature->setDirection (m_fBestDirection);
    else if (m_fPossibleDirection != -1.f)
        m_pCreature->setDirection (m_fPossibleDirection);
}
