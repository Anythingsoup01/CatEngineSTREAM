#pragma once

#include "Event.h"

namespace CatEngine
{
	// Key Base Class
	class KeyEvent : public Event
	{
	public:
		inline int GetKeycode() const { return m_Keycode; }

		EVENT_CLASS_CATEGORY(CategoryInputEvent | CategoryKeyboardEvent)
	protected:
		KeyEvent(int keycode)
			: m_Keycode(keycode) {}
		int m_Keycode;
	};

	// Key Pressed
	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed : " << m_Keycode << " (" << m_RepeatCount << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	// Key Typed
	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Typed : " << m_Keycode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyTyped)
	};

	// Key Released
	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released : " << m_Keycode;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased)
	};
}
