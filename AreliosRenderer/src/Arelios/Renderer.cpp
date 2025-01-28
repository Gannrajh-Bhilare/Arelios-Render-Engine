#include "areliospch.h"
#include "Renderer.h"

#include "Input.h"
#include "glad/glad.h"

namespace Arelios {

	Renderer::Renderer()
		:Layer("Renderer")
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::OnAttach()
	{

	}

	void Renderer::OnDetach()
	{

	}

	void Renderer::OnUpdate()
	{
		std::pair<float, float> mousePos = Input::GetMousePos();

		mousePos.first = mousePos.first / 1280.0f;
		mousePos.second = mousePos.second / 720.0f;

		glClearColor(mousePos.first, 0.0f, mousePos.second, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}