#pragma once
#include "Core.h"
#include "Window.h"

#include "Events/Events.h"
#include "Events/ApplicationEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvents.h"

#include "LayerStack.h"

namespace Arelios {

	class ARELIOS_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning;
		LayerStack m_LayerStack;
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		void Run();
	private:
		bool OnWindowClose(WindowCloseEvent& windowCloseEvent);
	};

	Application* CreateApplication();
}