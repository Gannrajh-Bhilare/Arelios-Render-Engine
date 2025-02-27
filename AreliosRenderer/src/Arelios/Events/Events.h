#pragma once

#include "Arelios/Core.h"

namespace Arelios {
	
	enum class EventType {
		none = 0,
		WindowReSize, WindowLoseFocus, WindowFocus, WindowClose, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyRelease, KeyTyped,
		MousePressed, MouseReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		none = 0,
		EventCategoryApplication = Bit(0),
		EventCategoryInput = Bit(1),
		EventCategoryKeyboard = Bit(2),
		EventCategoryMouse = Bit(3),
		EventCategoryMouseButton = Bit(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
                               virtual EventType GetEventType() const override { return GetStaticEvent(); }\
                               virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(categotry) virtual int GetCategoryFlags() const override { return category; }

	class Event {
		friend class EventDispatcher;
	public:
		bool m_Handled = false;
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	private:
		Event& m_Event;
	public:
		EventDispatcher(Event& event)
			:m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}

			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}
