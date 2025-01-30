#pragma once

#include "Core.h"
#include "Events/Events.h"

namespace Arelios {

	class Layer {
	private:
		std::string m_DebugName;
	public:
		Layer(const std::string& layerName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		virtual void OnImGuiRender() {}

		inline const std::string& GetDebugName() { return m_DebugName; }
	};
}