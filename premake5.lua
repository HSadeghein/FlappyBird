workspace "FlappyBird"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "MyGameEngine/vendor/GLFW/include"

--include the premake file in GLFW
include "MyGameEngine/vendor/GLFW"

project "MyGameEngine"
	location "MyGameEngine"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .."/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"IMMORTAL_PLATFORM_WINDOWS",
		"IMMORTAL_BUILD_DLL"
	}

	postbuildcommands
	{
		{"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/FlappyBird"}
	}

	filter "configurations:Debug"
		defines "IMMORTAL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMMORTAL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMMORTAL_DIST"
		optimize "On"









project "FlappyBird"
	location "FlappyBird"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .."/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"

	}

	includedirs
	{
		"MyGameEngine/vendor/spdlog/include",
		"MyGameEngine/src",
		"MyGameEngine/vendor/GLFW/include"

	}

	links
	{
		"MyGameEngine"
	}
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	

	defines
	{
		"IMMORTAL_PLATFORM_WINDOWS",
	}


	filter "configurations:Debug"
		defines "IMMORTAL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "IMMORTAL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "IMMORTAL_DIST"
		optimize "On"
