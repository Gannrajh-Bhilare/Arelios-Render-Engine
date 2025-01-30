#include "areliospch.h"
#include "OpenGLRendererContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Arelios {

	OpenGLRendererContext::OpenGLRendererContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
	}

	void OpenGLRendererContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);

		//Loading GLAD for OpenGL
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	}

	void OpenGLRendererContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}