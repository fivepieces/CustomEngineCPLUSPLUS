#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "MouseEventListener.h"
class EventListener
{
public:
	EventListener() = delete;
	EventListener(const EventListener&) = delete;
	EventListener(EventListener&&) = delete;
	EventListener& operator=(const EventListener&) = delete;
	EventListener& operator=(EventListener&&) = delete;
	static void Update();
};

#endif //!EVENTLISTENER_H