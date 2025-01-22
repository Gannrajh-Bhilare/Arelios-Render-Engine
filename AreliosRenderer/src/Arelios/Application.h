#pragma once
#include "Core.h"
#include "Window.h"

#include "Events/Events.h"
#include "Events/ApplicationEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvents.h"

namespace Arelios {

	class ARELIOS_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning;
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& windowCloseEvent);
		bool OnKeyPress(KeyPressedEvent& keyPressedEvent);
	};

	Application* CreateApplication();
}