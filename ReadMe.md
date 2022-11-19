# MaC

Modeling as Code

## What is it ?

This project aims to create a new way of drawing 3D Mesh : using code.

With MaC, you will have the possibility to draw shapes, add runtime 
conditions to avoid rendering part of shapes, or changing their textures, 
create functions and struct if you want to share elements. 
For example, you may want to create a mesh for a lamp, and then apply this 
lamp several times in a big scene (like a room)... With MaC, you will have 
the possibility to create a Lamp struct, which will contains the definition
of a single Mesh, and then applying it several times in another scene using 
a loop !

Another advantage of MaC : no more big files on your project ! You will have 
the possibility to create "librairies" of struct and functions and then include
them in other `.mac` files. So you will have finer control over the rendering
and how your scene should be splitted.

## How to build it

Tools needed : 
* Visual Studio
* Visual Studio Code (with the C/C++ extension)

1. Open a VS Developer prompt (in Start -> All applications -> Visual Studio -> Developer Command Prompt)
2. In the new prompt run : `code from this folder
3. To build & debug the app, just press `F5`.

## Credits & License

This project was created by [Sylvain Nieuwlandt](https://an0rak.dev) which 
holds the complete Copyright on it. You do NOT have the permission to share,
read, update, fork... or do whatever with any part of it (including the source
code and final binaries) without the explicit (and written) authorization of 
Sylvain Nieuwlandt.