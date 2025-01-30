#include <iostream>
#include <Arelios.h>
#include "imgui/imgui.h"

class TestLayer : public Arelios::Layer {
public:
	TestLayer()
		:Layer("TestLayer")
	{
	}

	void OnUpdate() override
	{
	}

	void OnImGuiRender() override
	{
		bool notImp = false;
		ImGui::Begin("Test GUI", &notImp, 0);

		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Arelios::Event& e) override
	{
		Arelios::EventDispatcher eventDispatcher(e);

		if (e.GetEventType() == Arelios::EventType::KeyPressed)
		{
			Arelios::KeyPressedEvent& keyEvent = (Arelios::KeyPressedEvent&)e;
			std::cout << "KeyCode: " << (char)keyEvent.GetKeyCode() << std::endl;
		}

		eventDispatcher.Dispatch<Arelios::KeyPressedEvent>(std::bind(&TestLayer::OnKeyPressed, this, std::placeholders::_1));
	}

	bool OnKeyPressed(Arelios::KeyPressedEvent& e)
	{
		return true;
	}
};

class Sandbox : public Arelios::Application {
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
		PushLayer(new Arelios::Renderer());
	}

	~Sandbox()
	{
	}
};

Arelios::Application* Arelios::CreateApplication()
{
	return new Sandbox();
}