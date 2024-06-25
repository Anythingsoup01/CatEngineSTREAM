#pragma once

#include "Core/Window.h"

#include "Core/Log.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace CatEngine
{
	class Application
	{
	public:
		Application();
		~Application();

		void Run();

		void OnEvent(Event& event);

	private:
		bool m_Running = true;

		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<Window> m_Window;
	};

	Application* CreateApplication();
}