#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Arelios::Application* Arelios::CreateApplication();

int main(int argc, char** argv)
{
	Arelios::Application* app = Arelios::CreateApplication();
	app->Run();

	delete app;
}

#endif