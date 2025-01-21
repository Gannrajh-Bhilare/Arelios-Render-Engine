#pragma once
#include "Core.h"
#include "Window.h"

namespace Arelios {

	class ARELIOS_API Application
	{
	private:
		std::unique_ptr<Window> m_Window;
		bool m_IsRunning;
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}