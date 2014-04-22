#include "../include/CCollision.hpp"

CCollision::CCollision (CCreature *pCreature)
: CEvent (COLLISION)
{
    m_pCreature = pCreature;
}

CCollision::~CCollision ()
{
    m_pCreature = nullptr;
}

void CCollision::handle ()
{
    m_pCreature->denyMove ();
}

void CCollision::ignore ()
{

}
