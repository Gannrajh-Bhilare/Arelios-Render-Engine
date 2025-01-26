#include "areliospch.h"
#include "Renderer.h"

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
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}