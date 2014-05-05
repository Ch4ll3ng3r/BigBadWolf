#ifndef CCONTROLROTKAEPPCHEN_HPP_INCLUDED
#define CCONTROLROTKAEPPCHEN_HPP_INCLUDED

#include "CControlCreature.hpp"

class CControlRotkaeppchen : public CControlCreature
{
    public:
        CControlRotkaeppchen (CRotkaeppchen *pRotkaeppchen, CWolf *pWolf, CLevel *pLevel);

    private:
        void calculatePossibleMoves ();
        bool isDirectionChangeNecessary ();
};

#endif // CCONTROLROTKAEPPCHEN_HPP_INCLUDED
