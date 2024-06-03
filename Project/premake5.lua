-------------------------------------------------------------
-- Name: GameEngineSDL
-- Description: GameEngine built with SDL Library
-------------------------------------------------------------
project "GameEngineSDL"
	kind "WindowedApp"
	includedirs {
		"./",
		"./src/shaders/",
	}	
	
	-- Local Source Files
	files{
		'**.h',
		'**.cpp',
		'**.hlsl',
		'**.hlsli',
	}

	libdirs { }

	filter{"files:**.hlsl"}
		buildaction "None"

	filter{}
	
	vpaths {
	["Shaders"] = {"src/shaders/*.hlsl", "src/shaders/*.hlsli"},
	}

	debugdir "."