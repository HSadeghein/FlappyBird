#include "pch.h"
#include "Helper/helper.h"
#include "Application.h"


namespace Immortal
{
	Application::Application()
	{
	}

	Application::~Application()
	{
		Terminate();
	}

	void Application::Run()
	{
		//Initialization
		Application::Initialize();

		GLFWwindow* window = mp_Window->GetWindow();

		UpdateEvent e(0.0f,0.0f);
		mp_Window->OnUpdate(e);

	}
	

	int Application::Initialize()
	{
		//Set error call back
		glfwSetErrorCallback(error_callback);
		if (!glfwInit())
		{
			IMMORTAL_CORE_ERROR("GLFW is not initialized!!!");
			return -1;
		}
		//Create Window
		mp_Window = std::make_unique<Window>(640, 480);
		if (!mp_Window->m_IsInitialized)
		{
			IMMORTAL_CORE_ERROR("GLFW Window couldn't be created!!");
			return -1;
		}
		glfwMakeContextCurrent(mp_Window->GetWindow());

		//load GLAD
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			IMMORTAL_CORE_ERROR("Failed to initialize GLAD");
			return -1;
		}

		return 0;
	}

	void Application::Terminate()
	{
		mp_Window->Terminate();
		glfwTerminate();
	}
}