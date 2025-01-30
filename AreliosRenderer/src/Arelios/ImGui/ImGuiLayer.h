#pragma once
#include "Arelios/Layer.h"
#include "Arelios/Events/Events.h"
#include "Arelios/Events/ApplicationEvents.h"
#include "Arelios/Events/MouseEvents.h"
#include "Arelios/Events/KeyEvents.h"

namespace Arelios {

	class ImGuiLayer : public Layer {
	private:
		float m_Time = 0.0f;
	public:
		ImGuiLayer();
		~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate() override;
		void OnEvent(Event& e) override;

		void OnImGuiRender() override;

		void Begin();
		void End();
	};
}