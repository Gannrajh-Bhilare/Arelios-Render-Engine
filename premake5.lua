workspace "AreliosRenderer"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "AreliosRenderer/vendor/GLFW/include"
IncludeDir["Glad"] = "AreliosRenderer/vendor/Glad/include"
IncludeDir["ImGui"] = "AreliosRenderer/vendor/imgui"
IncludeDir["glm"] = "AreliosRenderer/vendor/glm"

include "AreliosRenderer/vendor/GLFW"
include "AreliosRenderer/vendor/Glad"
include "AreliosRenderer/vendor/imgui"

project "AreliosRenderer"
	location "AreliosRenderer"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "areliospch.h"
	pchsource "AreliosRenderer/src/areliospch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"glm",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines 
		{
			"AS_DEBUG",
			"AS_ENABLE_ASSERTS"
		}
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AS_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"AreliosRenderer/src",
		"AreliosRenderer/vendor/glm"
	}

	links
	{
		"AreliosRenderer",
		"glm"
	}

	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "AS_Release"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		runtime "Release"
		optimize "On"