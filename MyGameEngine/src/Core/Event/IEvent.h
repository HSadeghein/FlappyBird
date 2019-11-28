#pragma once
class IEvent
{
public:
protected:
	EventTypes type = EventTypes::None;
};

enum class EventTypes
{
	None = 0,
	MouseMoved,
	LeftMouseCliked,
	RightMouseClicked,
	MouseScrolled,
	KeyPressed,
	KeyReleased,
	WindowSizeChanged,
};
