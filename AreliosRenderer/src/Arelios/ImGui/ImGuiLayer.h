#pragma once
#include "Arelios/Layer.h"
#include "Arelios/Events/Events.h"
#include "Arelios/Events/ApplicationEvents.h"
#include "Arelios/Events/MouseEvents.h"
#include "Arelios/Events/KeyEvents.h"

namespace Arelios {

	class ARELIOS_API ImGuiLayer : public Layer {
	private:
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate() override;
		void OnEvent(Event& e) override;

	private:
		bool OnKeyPressed(KeyPressedEvent& keyPressedEvent);
		bool OnKeyReleased(KeyReleasedEvent& keyReleasedEvent);
		bool OnKeyTyped(KeyTypedEvent& keyTypedEvent);

		bool OnMouseMoved(MouseMovedEvent& mouseMovedEvent);
		bool OnMousePressed(MouseButtonPressedEvent& mousePressedEvent);
		bool OnMouseReleased(MouseButtonReleasedEvent& mouseReleasedEvent);
		bool OnMouseScrolled(MouseScrolledEvent& mouseScrolledEvent);

		bool OnWindowReSize(WindowReSizeEvent& mouseReSizeEvent);
	};
}