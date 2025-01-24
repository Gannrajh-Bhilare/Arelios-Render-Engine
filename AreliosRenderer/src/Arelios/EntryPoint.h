#pragma once

#ifdef AS_PLATFORM_WINDOWS

//Function included in Sandbox
extern Arelios::Application* Arelios::CreateApplication();

//Entry point for the application
int main(int argc, char** argv)
{
	//Application created of type sandbox
	Arelios::Application* app = Arelios::CreateApplication();
	app->Run();

	delete app;
}

#endif