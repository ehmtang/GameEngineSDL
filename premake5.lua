-------------------------------------------------------------
-- Name: PBE Workspace
-------------------------------------------------------------
workspace "GameEngineSDL_Workspace"
  platforms { "x64" }
  configurations { "Debug", "Debug_ASan", "Release" }
  startproject "GameEngineSDL"

  filter "platforms:x64"
    system "windows"
    architecture "x86_64"
    defines { "_WIN32", "WIN32_LEAN_AND_MEAN", "NOMINMAX", "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING" }
    includedirs {
      "./Libraries/SDL2-2.30.7/include",
      "./Libraries/SDL2_image-2.8.2/include",
    }
    libdirs {
      "./Libraries/SDL2-2.30.7/lib/x64",
      "./Libraries/SDL2_image-2.8.2/lib/x64",
    }
    links { "SDL2", "SDL2main", "SDL2_image" }

  -- Debug Configuration
  filter "configurations:Debug"
    defines { "_DEBUG" }
    symbols "On"
    optimize "Off"
    editandcontinue "Off"

  -- Release Configuration
  filter "configurations:Release"
    defines { "NDEBUG" }
    symbols "On"
    optimize "Speed"
    editandcontinue "Off"

  -- AddressSanitizer Configuration
  filter "configurations:Debug_ASan"
    sanitize { "Address" }
    editandcontinue "Off"

  -- Use the latest Windows SDK
  filter "system:x64"
    systemversion "latest"

  -- General settings for all configurations
  filter {}
    language "C++"
    cppdialect "C++20"
    warnings "Extra"
    flags { "MultiProcessorCompile" }
    characterset "Unicode"
    location("Build/")

include "Libraries/premake5.lua"
include "Project/premake5.lua"
