#pragma once

#include "Event.h"

namespace CatEngine
{
	// Base Class
	class OnMouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(CategoryInputEvent | CategoryMouseButtonEvent)
	protected:
		OnMouseButtonEvent(int button)
			: m_Button(button) {}
		int m_Button;
	};

	// Mouse Button Pressed
	class OnMouseButtonPressedEvent : public OnMouseButtonEvent
	{
	public:
		OnMouseButtonPressedEvent(int button)
			: OnMouseButtonEvent(button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed (" << m_Button << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	// Mouse Button Released
	class OnMouseButtonReleasedEvent : public OnMouseButtonEvent
	{
	public:
		OnMouseButtonReleasedEvent(int button)
			: OnMouseButtonEvent(button) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released (" << m_Button << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	// Mouse Moved
	class MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(unsigned int mouseX, unsigned int mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		unsigned int GetMouseX() const { return m_MouseX; }
		unsigned int GetMouseY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Moved x" << m_MouseX << ", y" << m_MouseY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(CategoryInputEvent | CategoryMouseEvent)
	private:
		unsigned int m_MouseX, m_MouseY;
	};

	// Mouse Moved
	class MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		unsigned int GetOffsetX() const { return m_OffsetX; }
		unsigned int GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled x" << m_OffsetX << ", y" << m_OffsetY;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(CategoryInputEvent | CategoryMouseEvent)
	private:
		unsigned int m_OffsetX, m_OffsetY;
	};
}
