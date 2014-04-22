#ifndef COLLISION_HPP_INCLUDED
#define COLLISION_HPP_INCLUDED

#include "CEvent.hpp"

class CCollision : public CEvent
{
    public:
        CCollision (CCreature *pCreature);
        ~CCollision ();
        void handle ();
        void ignore ();

    private:
        CCreature *m_pCreature;
};

#endif // COLLISION_HPP_INCLUDED
