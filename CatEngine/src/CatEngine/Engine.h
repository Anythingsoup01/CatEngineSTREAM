#pragma once

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