#pragma once

#include "CatEngine/Core/Window.h"

#include "GLFW/glfw3.h"

namespace CatEngine {

	class WindowsWindow : public Window
	{
	public:

		WindowsWindow(const WindowProps& props);
		
		~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() override;

		void* GetNativeWindow() const override;
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	};

}