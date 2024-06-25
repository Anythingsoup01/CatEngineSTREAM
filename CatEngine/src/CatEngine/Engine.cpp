#include "cepch.h"
#include "Engine.h"

namespace CatEngine
{
	Application::Application()
	{
		WindowClosedEvent e;
		API_INFO(e.ToString());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{

		}
	}
}