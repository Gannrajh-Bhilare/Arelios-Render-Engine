#pragma once
#include "Core.h"
#include <iostream>

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