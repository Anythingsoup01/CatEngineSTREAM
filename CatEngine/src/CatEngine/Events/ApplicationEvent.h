#pragma once

#include "Event.h"

namespace CatEngine
{
	//WindowClosed, WindowResized, WindowFocus, WindowLostFocus, WindowMaximized, WindowMinimized, WindowMoved,
	// Window Close
	class WindowClosedEvent : public Event
	{
	public:
		WindowClosedEvent() {}
		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
	// Window Resize
	class WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height) {}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Window Resized (x" << m_Width << ", y" << m_Height << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	private:
		unsigned int m_Width, m_Height;
	};
	// Focus Event
	class WindowFocusEvent : public Event
	{
	public:
		WindowFocusEvent() {}
		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
	// Focus Lost Event
	class WindowLostFocusEvent : public Event
	{
	public:
		WindowLostFocusEvent() {}
		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
	class WindowMaximizedEvent : public Event
	{
	public:
		WindowMaximizedEvent() {}
		EVENT_CLASS_TYPE(WindowMaximized)
			EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
	class WindowMinimizedEvent : public Event
	{
	public:
		WindowMinimizedEvent() {}
		EVENT_CLASS_TYPE(WindowMinimized)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
	class WindowMovedEvent : public Event
	{
	public:
		WindowMovedEvent() {}
		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(CategoryApplicationEvent)
	};
}