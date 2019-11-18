#pragma once
#include "Core.h"
#include "Log.h"
#include "Window.h"
#include <GLFW/glfw3.h>
namespace Immortal
{
	class IMMORTAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		int Initialize();
		std::unique_ptr<Window> mp_Window;

		
		
	};

	//To bedefined in Client
	Application* CreateApplication();
}
