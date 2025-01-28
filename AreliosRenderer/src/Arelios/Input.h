#pragma once
#include "Arelios/Core.h"

namespace Arelios {

	class ARELIOS_API Input {
	private:
		static Input* s_Instance;
	public:
		//Input get functions
		static bool IsKeyPressed(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		static bool IsKeyReleased(int keyCode) { return s_Instance->IsKeyPressedImpl(keyCode); }
		static bool IsMousePressed(int mouseCode) { return s_Instance->IsKeyPressedImpl(mouseCode); }
		static bool IsMouseReleased(int mouseCode) { return s_Instance->IsKeyPressedImpl(mouseCode); }

		//Mouse position functions
		static std::pair<int, int> GetMousePos() { return s_Instance->GetMousePosImpl(); }
		static int GetMousePosX() { return s_Instance->GetMousePosXImpl(); }
		static int GetMousePosY() { return s_Instance->GetMousePosYImpl(); }
	protected:
		//Input get functions implentation
		virtual bool IsKeyPressedImpl(int keyCode) = 0;
		virtual bool IsKeyReleasedImpl(int keyCode) = 0;
		virtual bool IsMousePressedImpl(int mouseCode) = 0;
		virtual bool IsMouseReleasedImpl(int mouseCode) = 0;

		//Mouse position functions
		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual float GetMousePosXImpl() = 0;
		virtual float GetMousePosYImpl() = 0;
	};

	enum class KeyCode {
		NONE = 0,
		Space,
	};
}
