#pragma once

#include "Core/Log.h"

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