workspace "AreliosRenderer"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-{cfg.architecture}"

--Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "AreliosRenderer/vendor/GLFW/include"

include "AreliosRenderer/vendor/GLFW"

project "AreliosRenderer"
	location "AreliosRenderer"
	kind "SharedLib"
	language "C++"

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
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "c++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines 
		{
			"AS_DEBUG",
			"AS_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		defines "AS_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"AreliosRenderer/src"
	}

	links
	{
		"AreliosRenderer"
	}

	filter "system:windows"
		cppdialect "c++14"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "AS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "AS_Release"
		optimize "On"

	filter "configurations:Dist"
		defines "AS_DIST"
		optimize "On"