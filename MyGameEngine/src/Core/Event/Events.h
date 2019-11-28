#pragma once
#include "pch.h"
#include"IEvent.h"
#include "Core/Window.h"

namespace Immortal
{
	class IMMORTAL_API WindowSizeChanged : IEvent
	{
	public:
		typedef IEvent base;
		WindowSizeChanged(int width, int height) : m_Width(width), m_Height(height)
		{
			type = EventTypes::WindowSizeChanged;
		}
		//the new width and height of the window

		int m_Width; int m_Height;

	protected:

	};
	class IMMORTAL_API UpdateEvent : public IEvent
	{
	public:
		typedef IEvent base;
		UpdateEvent(double fDeltaTime, double fTotalTime)
			: ElapsedTime(fDeltaTime)
			, TotalTime(fTotalTime)
		{}

		double ElapsedTime;
		double TotalTime;
	};


}