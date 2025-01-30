#pragma once
#include "Core.h"
#include "Window.h"

#include "Events/Events.h"
#include "Events/ApplicationEvents.h"
#include "Events/MouseEvents.h"
#include "Events/KeyEvents.h"

#include "LayerStack.h"
#include "ImGui/ImGuiLayer.h"

namespace Arelios {

	class   Application
	{
	private:
		static Application* s_Instance;
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* imGuiLayer;

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

		inline static Application& GetInstance() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& windowCloseEvent);
	};

	Application* CreateApplication();
}