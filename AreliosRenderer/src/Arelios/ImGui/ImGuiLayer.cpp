#include "areliospch.h"
#include "ImGuiLayer.h"

#include "imgui.h"
#include "Platform/OpenGL/imGuiOpenGLRenderer.h"
#include "Arelios/Application.h"

#include <GLFW/glfw3.h>

namespace Arelios {

	ImGuiLayer::ImGuiLayer()
		:Layer("ImGuiLayer")
	{

	}
	
	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach()
	{

	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& application = Application::GetInstance();
		io.DisplaySize = ImVec2(application.GetWindow().GetWidth(), application.GetWindow().GetHeight()); 

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& e)
	{

	}
}