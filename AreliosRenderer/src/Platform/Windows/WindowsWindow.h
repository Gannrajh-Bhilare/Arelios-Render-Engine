#pragma once

#include "Arelios/Window.h"
#include <GLFW/glfw3.h>

namespace Arelios {

	class WindowsWindow : public Window {
	private:
		GLFWwindow* m_Window;
		
		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool VSync;

			EventCallBackFn EventCallBack;
		};

		WindowData m_WindowData;
	public:
		WindowsWindow(const WindowProp& prop);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_WindowData.width; }
		inline unsigned int GetHeight() const override { return m_WindowData.height; }

		inline void SetEventCallBack(const EventCallBackFn& callback) override { m_WindowData.EventCallBack = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline void* GetNativeWindow() override { return m_Window; }
	private:
		virtual void Init(const WindowProp& props);
		virtual void ShutDown();
	};
}
