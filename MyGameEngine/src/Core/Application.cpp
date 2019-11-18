#include "Application.h"

namespace Immortal
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Application::Initialize();
		while (true);
	}

	int Application::Initialize()
	{
		if (!glfwInit())
		{
			IMMORTAL_CORE_ERROR("GLFW not initialized!!!");
			return -1;
		}
		mp_Window = std::make_unique<Window>(640, 480);
		if (!mp_Window->m_IsInitialized)
			return -1;

		glfwMakeContextCurrent(mp_Window->mp_Widnow);
		return 0;
	}
}