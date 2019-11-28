#include "pch.h"
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
	void Window::SetWindowSize(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		glfwSetWindowSize(mp_Window, width, height);
	}
	void Window::OnResize(WindowSizeChanged& e)
	{
		if (e.m_Height != m_Height || e.m_Width != m_Width)
		{
			SetWindowSize(e.m_Width, e.m_Height);

		}
	}

	void Window::OnUpdate(UpdateEvent& e)
	{

		while (!glfwWindowShouldClose(mp_Window))
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwSwapBuffers(mp_Window);
			glfwPollEvents();
		}
	}


	void WindowSizeCallback(GLFWwindow* window, int width, int height)
	{
		
	}
	Window::Window(int width, int height)
	{
		m_Width = width;
		m_Height = height;
		mp_Window = glfwCreateWindow(width, height, "HI", NULL, NULL);
		if (!mp_Window)
		{
			IMMORTAL_CORE_ERROR("GLFW window could not be created!!!");
			m_IsInitialized = false;
		}
		m_IsInitialized = true;
		glfwSetWindowSizeCallback(mp_Window, WindowSizeCallback);

	}
	Window::~Window()
	{
		//Terminate();
	}

	void Window::Terminate()
	{
		glfwDestroyWindow(mp_Window);
	}

	GLFWwindow* Window::GetWindow()
	{
		return mp_Window;
	}
}