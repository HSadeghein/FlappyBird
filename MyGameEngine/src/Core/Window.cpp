#include "Window.h"

namespace Immortal
{
	int Window::GetHeight()
	{
		return Window::m_Height;
	}
	int Window::GetWidth()
	{
		return Window::m_Width;
	}

	void Window::SetHeight(int height)
	{
		m_Height = height;
	}
	void Window::SetWidth(int width)
	{
		m_Width = width;
	}

	Window::Window(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		mp_Widnow = glfwCreateWindow(width, height, "HI", NULL, NULL);
		m_IsInitialized = true;
		if (!mp_Widnow)
		{
			IMMORTAL_CORE_ERROR("GLFW window could not be created!!!");
			m_IsInitialized = false;
		}
	}
}