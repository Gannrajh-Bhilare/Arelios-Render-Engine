#include "areliospch.h"

#include "Application.h"
#include "Events/Events.h"
#include "Events/WindowEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvent.h"

#include "GLFW/glfw3.h"

namespace Arelios {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_IsRunning)
		{
			glClearColor(0.3f, 0.3f, 0.4f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}