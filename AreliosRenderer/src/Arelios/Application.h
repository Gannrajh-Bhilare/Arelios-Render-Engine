#pragma once
#include "Core.h"

namespace Arelios {

	class ARELIOS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}