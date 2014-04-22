#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include "EventType.hpp"
#include "CCreature.hpp"

class CEvent
{
    public:
        CEvent (EEventType Type);
        virtual ~CEvent();
        EEventType getType ();
        virtual void handle () = 0;
        virtual void ignore () = 0;

    protected:
        EEventType m_Type;
};

#endif // EVENT_HPP_INCLUDED
