#include "../include/CMovement.hpp"

CMovement::CMovement (CCreature *pCreature)
: CEvent (MOVEMENT)
{
    m_pCreature = pCreature;
}

CMovement::~CMovement()
{
    m_pCreature = nullptr;
}

void CMovement::handle ()
{
    m_pCreature->confirmMove ();
}

void CMovement::ignore ()
{

}
