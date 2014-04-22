#ifndef MOVEMENT_HPP_INCLUDED
#define MOVEMENT_HPP_INCLUDED

#include "CEvent.hpp"


class CMovement : public CEvent
{
    public:
        CMovement (CCreature *pCreature);
        ~CMovement ();
        void handle ();
        void ignore ();

    private:
        CCreature *m_pCreature;
};

#endif // MOVEMENT_HPP_INCLUDED
