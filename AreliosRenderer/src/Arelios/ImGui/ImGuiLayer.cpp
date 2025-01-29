#include "areliospch.h"
#include "ImGuiLayer.h"
#include "Arelios/Application.h"

#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Arelios {

    ImGuiKey GLFWKeyToImGuiKey(int keycode)
    {
        switch (keycode)
        {
        case GLFW_KEY_TAB: return ImGuiKey_Tab;
        case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
        case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
        case GLFW_KEY_UP: return ImGuiKey_UpArrow;
        case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
        case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case GLFW_KEY_HOME: return ImGuiKey_Home;
        case GLFW_KEY_END: return ImGuiKey_End;
        case GLFW_KEY_INSERT: return ImGuiKey_Insert;
        case GLFW_KEY_DELETE: return ImGuiKey_Delete;
        case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case GLFW_KEY_SPACE: return ImGuiKey_Space;
        case GLFW_KEY_ENTER: return ImGuiKey_Enter;
        case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
        case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case GLFW_KEY_COMMA: return ImGuiKey_Comma;
        case GLFW_KEY_MINUS: return ImGuiKey_Minus;
        case GLFW_KEY_PERIOD: return ImGuiKey_Period;
        case GLFW_KEY_SLASH: return ImGuiKey_Slash;
        case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case GLFW_KEY_EQUAL: return ImGuiKey_Equal;
        case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case GLFW_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case GLFW_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case GLFW_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case GLFW_KEY_PAUSE: return ImGuiKey_Pause;
        case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
        case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
        case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
        case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
        case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
        case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
        case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
        case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
        case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
        case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
        case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case GLFW_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case GLFW_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case GLFW_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case GLFW_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case GLFW_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case GLFW_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case GLFW_KEY_MENU: return ImGuiKey_Menu;
        case GLFW_KEY_0: return ImGuiKey_0;
        case GLFW_KEY_1: return ImGuiKey_1;
        case GLFW_KEY_2: return ImGuiKey_2;
        case GLFW_KEY_3: return ImGuiKey_3;
        case GLFW_KEY_4: return ImGuiKey_4;
        case GLFW_KEY_5: return ImGuiKey_5;
        case GLFW_KEY_6: return ImGuiKey_6;
        case GLFW_KEY_7: return ImGuiKey_7;
        case GLFW_KEY_8: return ImGuiKey_8;
        case GLFW_KEY_9: return ImGuiKey_9;
        case GLFW_KEY_A: return ImGuiKey_A;
        case GLFW_KEY_B: return ImGuiKey_B;
        case GLFW_KEY_C: return ImGuiKey_C;
        case GLFW_KEY_D: return ImGuiKey_D;
        case GLFW_KEY_E: return ImGuiKey_E;
        case GLFW_KEY_F: return ImGuiKey_F;
        case GLFW_KEY_G: return ImGuiKey_G;
        case GLFW_KEY_H: return ImGuiKey_H;
        case GLFW_KEY_I: return ImGuiKey_I;
        case GLFW_KEY_J: return ImGuiKey_J;
        case GLFW_KEY_K: return ImGuiKey_K;
        case GLFW_KEY_L: return ImGuiKey_L;
        case GLFW_KEY_M: return ImGuiKey_M;
        case GLFW_KEY_N: return ImGuiKey_N;
        case GLFW_KEY_O: return ImGuiKey_O;
        case GLFW_KEY_P: return ImGuiKey_P;
        case GLFW_KEY_Q: return ImGuiKey_Q;
        case GLFW_KEY_R: return ImGuiKey_R;
        case GLFW_KEY_S: return ImGuiKey_S;
        case GLFW_KEY_T: return ImGuiKey_T;
        case GLFW_KEY_U: return ImGuiKey_U;
        case GLFW_KEY_V: return ImGuiKey_V;
        case GLFW_KEY_W: return ImGuiKey_W;
        case GLFW_KEY_X: return ImGuiKey_X;
        case GLFW_KEY_Y: return ImGuiKey_Y;
        case GLFW_KEY_Z: return ImGuiKey_Z;
        case GLFW_KEY_F1: return ImGuiKey_F1;
        case GLFW_KEY_F2: return ImGuiKey_F2;
        case GLFW_KEY_F3: return ImGuiKey_F3;
        case GLFW_KEY_F4: return ImGuiKey_F4;
        case GLFW_KEY_F5: return ImGuiKey_F5;
        case GLFW_KEY_F6: return ImGuiKey_F6;
        case GLFW_KEY_F7: return ImGuiKey_F7;
        case GLFW_KEY_F8: return ImGuiKey_F8;
        case GLFW_KEY_F9: return ImGuiKey_F9;
        case GLFW_KEY_F10: return ImGuiKey_F10;
        case GLFW_KEY_F11: return ImGuiKey_F11;
        case GLFW_KEY_F12: return ImGuiKey_F12;
        case GLFW_KEY_F13: return ImGuiKey_F13;
        case GLFW_KEY_F14: return ImGuiKey_F14;
        case GLFW_KEY_F15: return ImGuiKey_F15;
        case GLFW_KEY_F16: return ImGuiKey_F16;
        case GLFW_KEY_F17: return ImGuiKey_F17;
        case GLFW_KEY_F18: return ImGuiKey_F18;
        case GLFW_KEY_F19: return ImGuiKey_F19;
        case GLFW_KEY_F20: return ImGuiKey_F20;
        case GLFW_KEY_F21: return ImGuiKey_F21;
        case GLFW_KEY_F22: return ImGuiKey_F22;
        case GLFW_KEY_F23: return ImGuiKey_F23;
        case GLFW_KEY_F24: return ImGuiKey_F24;
        default: return ImGuiKey_None;
        }
    }

    ImGuiKey ImGuiIsKeyMod(ImGuiKey& imguiKey)
    {
        switch (imguiKey)
        {
        case ImGuiKey_LeftCtrl:    return ImGuiKey_ModCtrl;
        case ImGuiKey_RightCtrl:   return ImGuiKey_ModCtrl;
        case ImGuiKey_LeftShift:   return ImGuiKey_ModShift;
        case ImGuiKey_RightShift:  return ImGuiKey_ModShift;
        case ImGuiKey_LeftAlt:     return ImGuiKey_ModAlt;
        case ImGuiKey_RightAlt:    return ImGuiKey_ModAlt;
        case ImGuiKey_LeftSuper:   return ImGuiKey_ModSuper;
        case ImGuiKey_RightSuper:  return ImGuiKey_ModSuper;
        default: return ImGuiKey_None;
        }
    }

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
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

        ImGui::StyleColorsDark;

        ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(Application::GetInstance().GetWindow().GetNativeWindow()), true);
        ImGui_ImplOpenGL3_Init("#version 410 core");

        bool showDemoWindow = true;
        ImVec4 clearColor = ImVec4(0.45f, 0.55f, 0.60f, 1.0f);
	}

	void ImGuiLayer::OnDetach()
	{
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
	}

	void ImGuiLayer::OnUpdate()
	{
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow((bool*)true);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event& e)
	{
		EventDispatcher eventDispatcher(e);

        eventDispatcher.Dispatch<MouseMovedEvent>(std::bind(&ImGuiLayer::OnMouseMoved, this, std::placeholders::_1));
		eventDispatcher.Dispatch<KeyPressedEvent>(std::bind(&ImGuiLayer::OnKeyPressed, this, std::placeholders::_1));
        eventDispatcher.Dispatch<KeyReleasedEvent>(std::bind(&ImGuiLayer::OnKeyReleased, this, std::placeholders::_1));
        eventDispatcher.Dispatch<KeyTypedEvent>(std::bind(&ImGuiLayer::OnKeyTyped, this, std::placeholders::_1));

		eventDispatcher.Dispatch<MouseButtonPressedEvent>(std::bind(&ImGuiLayer::OnMousePressed, this, std::placeholders::_1));
        eventDispatcher.Dispatch<MouseButtonReleasedEvent>(std::bind(&ImGuiLayer::OnMouseReleased, this, std::placeholders::_1));
        eventDispatcher.Dispatch<MouseScrolledEvent>(std::bind(&ImGuiLayer::OnMouseScrolled, this, std::placeholders::_1));
	}

	bool ImGuiLayer::OnKeyPressed(KeyPressedEvent& keyPressedEvent)
	{
		ImGuiIO& io = ImGui::GetIO();
        ImGuiKey imguiKey = GLFWKeyToImGuiKey(keyPressedEvent.GetKeyCode());

        ImGuiKey modKey = ImGuiIsKeyMod(imguiKey);

        if (modKey != ImGuiKey_None)
            io.AddKeyEvent(modKey, true);

        io.AddKeyEvent(imguiKey, true);
        
		return false;
	}

    bool ImGuiLayer::OnKeyReleased(KeyReleasedEvent& keyReleasedEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGuiKey imguiKey = GLFWKeyToImGuiKey(keyReleasedEvent.GetKeyCode());

        ImGuiKey modKey = ImGuiIsKeyMod(imguiKey);

        if (modKey != ImGuiKey_None)
            io.AddKeyEvent(modKey, false);

        io.AddKeyEvent(imguiKey, false);

        return false;
    }

    bool ImGuiLayer::OnKeyTyped(KeyTypedEvent& keyTypedEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter((unsigned int)keyTypedEvent.GetKeyCode());

        return false;
    }

    bool ImGuiLayer::OnMouseMoved(MouseMovedEvent& mouseMovedEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMousePosEvent(mouseMovedEvent.GetX(), mouseMovedEvent.GetY());

        return false;
    }

	bool ImGuiLayer::OnMousePressed(MouseButtonPressedEvent& mousePressedEvent)
	{
        ImGuiIO& io = ImGui::GetIO();
        int button = mousePressedEvent.GetMouseButton();

        if (button < ImGuiMouseButton_COUNT)
            io.AddMouseButtonEvent(button, true);

		return false;
	}

    bool ImGuiLayer::OnMouseReleased(MouseButtonReleasedEvent& mouseReleasedEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        int button = mouseReleasedEvent.GetMouseButton();

        if (button < ImGuiMouseButton_COUNT)
            io.AddMouseButtonEvent(button, false);

        return false;
    }

    bool ImGuiLayer::OnMouseScrolled(MouseScrolledEvent& mouseScrolledEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseWheelEvent(mouseScrolledEvent.GetX(), mouseScrolledEvent.GetY());

        return false;
    }

    bool ImGuiLayer::OnWindowReSize(WindowReSizeEvent& mouseReSizeEvent)
    {
        ImGuiIO& io = ImGui::GetIO();
        int width = mouseReSizeEvent.GetWidth();
        int height = mouseReSizeEvent.GetHeight();

        io.DisplaySize = ImVec2(width, height);
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, width, height);

        return true;
    }
}