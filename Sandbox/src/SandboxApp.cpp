#include <iostream>
#include <Arelios.h>

#include "glm/glm.hpp"

class TestLayer : public Arelios::Layer {
public:
	TestLayer()
		:Layer("TestLayer")
	{
	}

	void OnUpdate() override
	{
		glm::vec4 someValue = glm::vec4(5.0f, 0.0f, 50.0f, 10.0f);

		if (Arelios::Input::IsKeyPressed(AS_KEY_F))
			std::cout << "The value is (" << someValue.x << ", " << someValue.y << ", " << someValue.z << std::endl;
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
		PushOverlay(new Arelios::ImGuiLayer());
	}

	~Sandbox()
	{
	}
};

Arelios::Application* Arelios::CreateApplication()
{
	return new Sandbox();
}