#include "../include/CControlWolf.hpp"

CControlWolf::CControlWolf (CWolf *pWolf, CRotkaeppchen *pRotkaeppchen, CLevel *pLevel)
: CControlCreature (pWolf, pRotkaeppchen, pLevel)
{
    //ctor
}

void CControlWolf::calculatePossibleMoves ()
{
    float fOriginalDirection = m_pCreature->getDirection ();
    m_dOldDistance = m_dCurDistance;
    m_fBestDirection = -1.f;
    m_fPossibleDirection = -1.f;
    for (int i = 0; i < 4; i++)
    {
        m_pCreature->setDirection (90.f * static_cast<float> (i));
        m_pCreature->move (m_uiElapsedTime);
        calculateDistance ();
        if (!m_pLevel->checkCollision (m_pCreature->getPos (), m_pCreature->getSize ()))
        {
            m_fPossibleDirection = 90.f * static_cast<float> (i);
            if (m_dCurDistance < m_dOldDistance)
                m_fBestDirection = 90.f * static_cast<float> (i);
        }
        m_pCreature->denyMove ();
    }
    m_pCreature->setDirection (fOriginalDirection);
}

bool CControlWolf::isDirectionChangeNecessary ()
{
    bool bIsDirectionChangeNecessary = false;
    m_pCreature->move (m_uiElapsedTime);
    bIsDirectionChangeNecessary = ((m_dCurDistance >= m_dOldDistance) ||
                                   (m_pLevel->checkCollision (m_pCreature->getPos (), m_pCreature->getSize ())));
    m_pCreature->denyMove ();
    return bIsDirectionChangeNecessary;
}
