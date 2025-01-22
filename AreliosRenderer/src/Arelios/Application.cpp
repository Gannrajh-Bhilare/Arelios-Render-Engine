#include "areliospch.h"

#include "Application.h"
#include "GLFW/glfw3.h"

namespace Arelios {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallBack(BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);

		//Log the events
		std::clog << e.GetName() << '\r' << std::flush;
		
		eventDispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		eventDispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(OnKeyPress));
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

	bool Application::OnWindowClose(WindowCloseEvent& windowCloseEvent)
	{
		m_IsRunning = false;
		return true;
	}

	bool Application::OnKeyPress(KeyPressedEvent& keyPressedEvent)
	{
		if (keyPressedEvent.GetKeyCode() == GLFW_KEY_ESCAPE)
			m_IsRunning = false;

		return true;
	}
}