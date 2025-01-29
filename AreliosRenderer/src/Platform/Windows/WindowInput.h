#pragma once
#include <GLFW/glfw3.h>
#include "Arelios/Events/Input.h"

namespace Arelios {

	class WindowInput : public Input {
	protected:
		//Key pressed input implementation for windows
		bool IsKeyPressedImpl(int keyCode) override;
		bool IsKeyReleasedImpl(int keyCode) override;
		bool IsMousePressedImpl(int mouseCode) override;
		bool IsMouseReleasedImpl(int mouseCode) override;

		//Mouse position implementation for windows
		std::pair<float, float> GetMousePosImpl() override;
		float GetMousePosXImpl() override;
		float GetMousePosYImpl() override;
	};
}