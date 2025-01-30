#pragma once
#include "Arelios/Renderer/RendererContext.h"
struct GLFWwindow;

namespace Arelios {

	class OpenGLRendererContext : public RendererContext {
	private:
		GLFWwindow* m_WindowHandle;
	public:
		OpenGLRendererContext(GLFWwindow* windowHandle);

		void Init() override;
		void SwapBuffers() override;
	};
}