-------------------------------------------------------------
-- Name: GameEngineSDL
-- Description: GameEngine built with SDL Library
-------------------------------------------------------------
project "GameEngineSDL"
    kind "StaticLib" -- Can be None if it's just header-only libraries
    language "C++"

    includedirs {
        "./glm",
		"./glm/**"
    }

    files {
        "**.h",
        "**.hpp",
        "**.cpp"
    }
