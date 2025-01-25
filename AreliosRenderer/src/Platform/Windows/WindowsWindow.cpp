#include <areliospch.h>

#include "WindowsWindow.h"

#include "Arelios/Events/Events.h"
#include "Arelios/Events/ApplicationEvents.h"
#include "Arelios/Events/MouseEvents.h"
#include "Arelios/Events/KeyEvents.h"

#include <glad/glad.h>

namespace Arelios {

	static bool s_GLFWInitialised = false;

	static void GLFWErrorCallback(int errorCode, const char* description)
	{
		std::cout << "GLFW Error: (" << errorCode << ") : " << description;
		AS_ASSERT(true);
	}

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

		std::cout << "Creating Window: " << m_WindowData.title << " ( " << m_WindowData.height << ", " << m_WindowData.width << " )" << std::endl;

		if (!s_GLFWInitialised)
		{
			int success = glfwInit();
			AS_ASSERT(success);

			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialised = true;
		}

		m_Window = glfwCreateWindow(m_WindowData.width, m_WindowData.height, m_WindowData.title.c_str(), NULL, NULL);
		glfwMakeContextCurrent(m_Window);

		//Loading GLAD for OpenGL
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AS_ASSERT(status);

		glfwSetWindowUserPointer(m_Window, &m_WindowData);

		//GLFW event handling
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			WindowReSizeEvent windowReSizeEvent(width, height);
			data.EventCallBack(windowReSizeEvent);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			WindowCloseEvent windowCLoseEvent;
			data.EventCallBack(windowCLoseEvent);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent keyPressedEvent(key, 0);
					data.EventCallBack(keyPressedEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent keyReleasedEvent(key);
					data.EventCallBack(keyReleasedEvent);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent keyPressedEvent(key, 1);
					data.EventCallBack(keyPressedEvent);
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keyCode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent keyTypedEvent(keyCode);
			data.EventCallBack(keyTypedEvent);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int key, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent mousePressedEvent(key);
					data.EventCallBack(mousePressedEvent);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent mouseReleasedEvent(key);
					data.EventCallBack(mouseReleasedEvent);
					break;
				}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent mouseScrolledEvent((float)xOffset, (float)yOffset);
			data.EventCallBack(mouseScrolledEvent);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent mouseMovedEvent((float)xPos, (float)yPos);
			data.EventCallBack(mouseMovedEvent);
		});
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