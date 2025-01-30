#pragma once

#include "Events.h"

namespace Arelios {

	class MouseMovedEvent : public Event {
	private:
		float m_MouseX;
		float m_MouseY;
	public:
		MouseMovedEvent(float x, float y)
			:m_MouseX(x), m_MouseY(y) {}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << " , " << m_MouseY;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseMoved; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MouseMoved"; }

		virtual int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }
	};

	class MouseScrolledEvent : public Event {
	private:
		float m_XOffset;
		float m_YOffset;
	public:
		MouseScrolledEvent(float x, float y)
			:m_XOffset(x), m_YOffset(y) {}

		inline float GetX() const { return m_XOffset; }
		inline float GetY() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseScrolled; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MouseScrolled"; }

		virtual int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }
	};

	class MouseButtonEvent : public Event {
	protected:
		MouseButtonEvent(int button)
			:m_Button(button) {}

		int m_Button;
	public:
		inline int GetMouseButton() const { return m_Button; }

		virtual int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }
	};

	class MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MousePressed; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName() const override { return "MousePressed"; }
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button)
			:MouseButtonEvent(button) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		static EventType GetStaticType() { return EventType::MouseReleased; }
		virtual EventType GetEventType() const override { return GetStaticType(); }
		virtual const char* GetName()  const override { return "MouseReleased"; }
	};
}