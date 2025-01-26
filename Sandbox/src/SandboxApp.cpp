#include <iostream>
#include <Arelios.h>

class TestLayer : public Arelios::Layer {
public:
	TestLayer()
		:Layer("TestLayer")
	{
	}

	void OnUpdate() override
	{
		std::clog << this->GetDebugName() << " Updated\r" << std::flush;
	}

	void OnEvent(Arelios::Event& e) override
	{
		Arelios::EventDispatcher eventDispatcher(e);
		eventDispatcher.Dispatch<Arelios::KeyPressedEvent>(std::bind(&TestLayer::OnKeyPressed, this, std::placeholders::_1));
	}

	bool OnKeyPressed(Arelios::KeyPressedEvent& e)
	{
		//std::cout << "Key Pressed: " << e.GetKeyCode() << std::endl;
		return true;
	}
};

class Sandbox : public Arelios::Application {
public:
	Sandbox()
	{
		PushLayer(new Arelios::Renderer());
		PushLayer(new TestLayer());
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