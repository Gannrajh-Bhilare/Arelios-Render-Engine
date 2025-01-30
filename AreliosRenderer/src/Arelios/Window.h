#pragma once

#include "areliospch.h"
#include "Core.h"

#include "Events/Events.h"

namespace Arelios {

	struct WindowProp {
		std::string title;
		int width;
		int height;

		WindowProp(std::string Title = "Arelios Renderer", int Width = 1280, int Height = 720)
			:title(Title), width(Width), height(Height) {}
	};

	class Window {
	public:
		using EventCallBackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() = 0;

		static Window* Create(const WindowProp& prop = WindowProp());
	};
}