# Core-Framework
A game framework with 2D and 3D capabilities 

## Features
- Simple OOP opengl wrapper
- Load, edit and save images
- Create a texture from a image
- display a texture with a sprite
- Transformations
- 2D and 3D Views
- Simple Window
- Compatible with ImGui

## Planned Features
- 2D and 3D shapes like cube, circle, sphere, triangle, etc
- make imgui be optional
- cross platform
- pathfinding
- noise generation

## Build
this project uses meson as build system, to build do the following:

### Linux

        meson setup build
        meson compile -C build

Meson will download all required libraries and compile, then run the example with:

        ./build/src/example/Example

### Windows

windows needs mingw, download and install [mingw](https://github.com/niXman/mingw-builds-binaries/releases), select the x86_64 posix sjlj

        meson setup build-mingw --cross-file mingw_cross.txt
        meson compile -C build-mingw
        ./build-mingw/src/example/Example.exe

if everything went well, you will see a white place with a rotating image approaching

## Core uses the following libraries:
- glfw to create windows and manage input
- gleq as event handling system
- glew to use opengl
- glm to do the math
- stb to load and save images
- imgui to make window compatible with imgui
- fmt to print and format
