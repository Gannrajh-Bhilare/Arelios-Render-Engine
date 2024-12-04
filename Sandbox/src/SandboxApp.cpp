#include <iostream>
#include <Arelios.h>

class Sandbox : public Arelios::Application 
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Arelios::Application* Arelios::CreateApplication()
{
	return new Sandbox();
}