#pragma once
#include "Core.h"

namespace Immortal
{
	class IMMORTAL_API Application
	{

	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To bedefined in Client
	Application* CreateApplication();
}
