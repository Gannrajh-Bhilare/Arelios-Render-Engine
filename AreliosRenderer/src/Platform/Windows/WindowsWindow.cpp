#include <areliospch.h>
#include "WindowsWindow.h"

namespace Arelios {
	static bool s_GLFWInitialised = false;

	Window* Window::Create(const WindowProp& prop)
	{
		return new WindowsWindow(prop);
	}

	WindowsWindow::WindowsWindow(const WindowProp& prop)
	{
		Init(prop);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::Init(const WindowProp& prop)
	{
		m_WindowData.title = prop.title;
		m_WindowData.width = prop.width;
		m_WindowData.height = prop.height;

		std::cout << "Creating Window: " << m_WindowData.title << " ( " << m_WindowData.height << ", " << m_WindowData.width << " )";

		if (!s_GLFWInitialised)
		{
			int success = glfwInit();
			AS_ASSERT(success);

			s_GLFWInitialised = true;
		}

		m_Window = glfwCreateWindow(m_WindowData.width, m_WindowData.height, m_WindowData.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_WindowData.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_WindowData.VSync;
	}
}