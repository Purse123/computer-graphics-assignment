#OPENGL
- It is considered an API, provides with large set of function to manupulate graphics and images.
- People developing OpenGL libraries are graphics card manufactureres.


```sh
pkg-config --cflags --libs glfw3
```
output:
```sh
-I/usr/local/include -L/usr/local/lib64 -lglfw3
```
> -I/usr/local/include -> find GLFW header file <br>
> -L/usr/local/lib64 -> specifies GLFW library `libglfw.so` <br>
> -lglfw -> links program with glfw library