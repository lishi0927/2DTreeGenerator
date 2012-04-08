solution "2DTreeGenerator"

   configurations { "Debug", "Release" }
 
   project "2DTreeGenerator"

      kind "ConsoleApp"
      language "C++"

      location( "../" )
      objdir "obj"

      files { "../src/**.h", "../src/**.cpp" }
      links { "SDL"
      	    , "SDL_image" }

      if os.get() == "macosx" then
         links { "SDLmain", "Cocoa.framework", "OpenGL.framework" }
         libdirs { "/opt/local/lib" }
         includedirs { "/opt/local/include", "/usr/X11R6/include" }
      elseif os.get() == "linux" then
         links { "GL", "GLU" }
      end


      configuration "Debug"

         defines { "DEBUG" }
         flags { "Symbols" }
	 targetdir "../bin/debug"
 
      configuration "Release"

         defines { "NDEBUG" }
         flags { "Optimize" }
	 targetdir "../bin/release"