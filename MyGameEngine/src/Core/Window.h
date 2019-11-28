#pragma once
#include "pch.h"
#include "Core.h"
#include "Log.h"
#include "Event/Events.h"
namespace Immortal
{
	class IMMORTAL_API Window
	{
	public:
		Window(int width, int height);
		virtual ~Window();

		void SetWidth(int width);
		void SetHeight(int height);
		int GetHeight();
		int GetWidth();
		void SetWindowSize(int width, int height);
		GLFWwindow* GetWindow();
		void Terminate();

		//Events
		void OnResize(WindowSizeChanged& e);
		void OnUpdate(UpdateEvent& e);

		bool m_IsInitialized = false;
	private:



		int m_Width, m_Height;
		GLFWwindow* mp_Window;
	protected:
	};
}