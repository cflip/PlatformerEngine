# PlatformerEngine

## Build Instructions
### Windows
- Download [MinGW](https://sourceforge.net/projects/mingw-w64/files/) and make sure to install version 7.3.0
- Download [SFML](https://www.sfml-dev.org/download/sfml/2.5.1/) (make sure it's the SEH version!) and place it in `lib\SFML\`
- Download [ImGui](https://github.com/ocornut/imgui) and [ImGui-SFML]([ImGui](https://github.com/ocornut/imgui)) and put the files in `lib\ImGui\`
- Add the contents of `imconfig-SFML.h` to `imconfig.h`
- The CMake project hopefully works when you build it!