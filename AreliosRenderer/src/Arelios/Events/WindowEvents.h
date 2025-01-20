#pragma once

#include "Events.h"

namespace Arelios {
	
	class ARELIOS_API WindowReSizeEvent : public Event {
	private:
		int m_Width;
		int m_Height;
	public:
		WindowReSizeEvent(int width, int height)
			:m_Width(width), m_Height(height) {}

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "WindowReSize: " << "Width: " << m_Width << ", Height: " << m_Height;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::WindowReSize; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "WindowReSize"; }

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class ARELIOS_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		static EventType GetStaticType() { return EventType::WindowClose; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "WindowClose"; }

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class ARELIOS_API AppTickEvent : public Event {
	public:
		AppTickEvent() {}

		static EventType GetStaticType() { return EventType::AppTick; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppTick"; }

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class ARELIOS_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent() {}

		static EventType GetStaticType() { return EventType::AppUpdate; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppUpdate"; }

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
	};

	class ARELIOS_API AppRenderEvent : public Event {
	public:
		AppRenderEvent() {}

		static EventType GetStaticType() { return EventType::AppRender; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "AppRender"; }

		virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
	};
}
