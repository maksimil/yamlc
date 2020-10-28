project "yamlc"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir (Output["bin"])
    objdir (Output["obj"])

    files
    {
        "include/**.h",
        "src/**.c"
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug*"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release*"
        runtime "Release"
        optimize "on"
