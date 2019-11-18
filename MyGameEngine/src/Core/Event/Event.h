#pragma once
#include"IEvent.h"


class Event : IEvent
{
protected:
	EventTypes type;

};

enum class EventTypes
{
	None = 0,
	MouseMoved,
	LeftMouseCliked,
	RightMouseClicked,
	MouseScrolled,
	KeyPressed,
	KeyReleased
};