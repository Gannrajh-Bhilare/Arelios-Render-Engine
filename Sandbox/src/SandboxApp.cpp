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
		std::cout << this->GetDebugName() << ": " << e.GetName() << std::endl;
	}
};

class TestLayer2 : public Arelios::Layer {
public:
	TestLayer2()
		:Layer("TestLayer2")
	{
	}

	void OnUpdate() override
	{
		std::clog << this->GetDebugName() << " Updated\r" << std::flush;
	}

	void OnEvent(Arelios::Event& e) override
	{
		std::cout << this->GetDebugName() << ": " << e.GetName() << std::endl;
	}
};

class Sandbox : public Arelios::Application {
public:
	Sandbox()
	{
		PushLayer(new TestLayer());
		PushLayer(new TestLayer2());
	}

	~Sandbox()
	{

	}
};

Arelios::Application* Arelios::CreateApplication()
{
	return new Sandbox();
}