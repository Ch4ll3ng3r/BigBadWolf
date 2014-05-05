#ifndef CCONTROLWOLF_HPP_INCLUDED
#define CCONTROLWOLF_HPP_INCLUDED

#include "CControlCreature.hpp"

class CControlWolf : public CControlCreature
{
    public:
        CControlWolf (CWolf *pWolf, CRotkaeppchen *pRotkaeppchen, CLevel *pLevel);

    private:
        void calculatePossibleMoves ();
        bool isDirectionChangeNecessary ();
};

#endif // CCONTROLWOLF_HPP_INCLUDED
