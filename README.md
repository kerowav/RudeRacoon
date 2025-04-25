# RudeRacoon

Clone to have a VSCode ready OpenGL template environment.

Initial Setup  
You will need to have the GLFW pre-compiled binaries installed, and the destination of it's folder.  
  - The binaries can be installed from the GLFW website -> https://www.glfw.org/download.html

The destination for the binaries used in this project is `C:/dev/glfw`.  
If you would like to change the destination you can edit the `cmake/Findglfw3.cmake` file at the commented lines below.

```
set( _glfw3_HEADER_SEARCH_DIRS
"/usr/include"
"/usr/local/include"
"${CMAKE_SOURCE_DIR}/includes"
"C:/dev/glfw/include" )          # Change this directory here
set( _glfw3_LIB_SEARCH_DIRS
"/usr/lib"
"/usr/local/lib"
"${CMAKE_SOURCE_DIR}/lib"
"C:/dev/glfw/lib-vc2022" )       # Change this directory here
```

Once the initial setup is complete you should be able to Clone the repo

1.  Open workspace in VSCode
2.  Use hotkeys: ctrl+shift+p
3.  Select -> CMake: Configure
4.  Select your compiler
5.  Build Ready ✔
6.  At this point you can either
    1. Use the VSCode terminal to make the program by typing out each of these lines
       1. cd build
       2. make
       3. ./RudeRacoon.exe
    2. Use the debugger button at the bottom left of VSCode
       ![alt_text](https://www.dropbox.com/scl/fi/kjbzldvja9x4wdu8pouvs/tempsave-delete-later.png?rlkey=qnqidy9kxv87rguhv32jvmgdy&st=mwfmbabl&raw=1)
