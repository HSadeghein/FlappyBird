#pragma once
#ifdef IMMORTAL_PLATFORM_WINDOWS

extern Immortal::Application* Immortal::CreateApplication();
int main(int argc, char** argv)
{
	Immortal::Log::Init();
	IMMORTAL_CORE_INFO("Program Started");

	auto app = Immortal::CreateApplication();
	app->Run();
	delete app;
}

#endif
