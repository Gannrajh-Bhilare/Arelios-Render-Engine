#include "areliospch.h"
#include "Renderer.h"

#include "Arelios/Events/Input.h"
#include "glad/glad.h"

#include "glm/glm.hpp"

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

		glm::vec4 colour = glm::vec4(mousePos.first, 0.0f, mousePos.second, 1.0f);

		glClearColor(colour.x, colour.y, colour.z, colour.w);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}