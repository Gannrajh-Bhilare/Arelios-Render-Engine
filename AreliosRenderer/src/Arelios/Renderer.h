#pragma once
#include "Layer.h"

namespace Arelios {

	class Renderer : public Layer {
	public:
		Renderer();
		~Renderer() override;

		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate() override;
	};
}
