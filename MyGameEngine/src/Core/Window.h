#pragma once
#include "Core.h"
#include "Log.h"
#include <GLFW/glfw3.h>
namespace Immortal
{
	class IMMORTAL_API Window
	{
	public:
		void SetWidth(int width);
		void SetHeight(int height);
		int GetHeight();
		int GetWidth();
		bool m_IsInitialized = false;
		GLFWwindow* mp_Widnow;

		Window(int width, int height);
	private:
		int m_Width, m_Height;
	protected:
	};
}