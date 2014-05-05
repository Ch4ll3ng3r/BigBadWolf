#ifndef CCONTROLCREATURE_HPP_INCLUDED
#define CCONTROLCREATURE_HPP_INCLUDED

#include "CCreature.hpp"
#include "CLevel.hpp"
#include "CWolf.hpp"
#include "CRotkaeppchen.hpp"
#include <cmath>

class CControlCreature
{
    public:
        CControlCreature (CCreature *pCreature, CCreature *pEnemy, CLevel *pLevel);
        ~CControlCreature ();
        void update (unsigned int uiElapsedTime);

    protected:
        void calculateDistance ();
        void chooseBestMove ();
        virtual void calculatePossibleMoves () = 0;
        virtual bool isDirectionChangeNecessary () = 0;
        CCreature *m_pCreature;
        CCreature *m_pEnemy;
        CLevel *m_pLevel;
        float m_fBestDirection;
        float m_fPossibleDirection;
        unsigned int m_uiElapsedTime;
        double m_dCurDistance;
        double m_dOldDistance;
};

#endif // CCONTROLCREATURE_HPP_INCLUDED
