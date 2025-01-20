#include "areliospch.h"
#include "Application.h"
#include "Events/Events.h"
#include "Events/WindowEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvent.h"

namespace Arelios {

	Application::Application()
	{
		
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowReSizeEvent win(1920, 1080);
		std::cout << win.ToString() << std::endl;

		while (true)
		{
		}
	}
}