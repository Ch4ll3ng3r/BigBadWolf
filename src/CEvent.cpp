#include "../include/CEvent.hpp"

CEvent::CEvent (EEventType Type)
{
    m_Type = Type;
}

CEvent::~CEvent()
{
    // nothing
}

EEventType CEvent::getType ()
{
    return m_Type;
}
