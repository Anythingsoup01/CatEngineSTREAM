#pragma once

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
	private:
		bool m_Running = true;
	};

	Application* CreateApplication();
}