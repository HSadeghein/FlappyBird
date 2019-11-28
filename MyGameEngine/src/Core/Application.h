#pragma once
#include "pch.h"
#include "Core.h"
#include "Log.h"
#include "Window.h"

namespace Immortal
{
	class IMMORTAL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	protected:
		int Initialize();
		void Terminate();
		std::unique_ptr<Window> mp_Window;

		
		
	};

	//To bedefined in Client
	Application* CreateApplication();
}
