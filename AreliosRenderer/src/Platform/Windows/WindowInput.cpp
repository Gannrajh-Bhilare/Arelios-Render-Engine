#include "areliospch.h"
#include "WindowInput.h"
#include "Arelios/Application.h"

namespace Arelios {

	Input* Input::s_Instance = new WindowInput();

	bool WindowInput::IsKeyPressedImpl(int keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());

		int status = glfwGetKey(window, keyCode);
		return status == GLFW_PRESS || status == GLFW_REPEAT;
	}

	bool WindowInput::IsKeyReleasedImpl(int keyCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());

		int status = glfwGetKey(window, keyCode);
		return status == GLFW_RELEASE;
	}

	bool WindowInput::IsMousePressedImpl(int mouseCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());

		int status = glfwGetMouseButton(window, mouseCode);
		return status == GLFW_RELEASE || status == GLFW_REPEAT;
	}

	bool WindowInput::IsMouseReleasedImpl(int mouseCode)
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());

		int status = glfwGetMouseButton(window, mouseCode);
		return status == GLFW_RELEASE;
	}

	std::pair<float, float> WindowInput::GetMousePosImpl()
	{
		GLFWwindow* window = static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow());
		double xPos, yPos;

		glfwGetCursorPos(window, &xPos, &yPos);

		return { xPos, yPos };
	}

	float WindowInput::GetMousePosXImpl()
	{
		auto[x, y] = GetMousePosImpl();
		return x;
	}

	float WindowInput::GetMousePosYImpl()
	{
		auto[x, y] = GetMousePosImpl();
		return y;
	}
}
