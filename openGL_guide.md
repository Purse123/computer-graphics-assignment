# GLFW from docs
- It is a multi-platform libarary for OpenGL, OpenGL ES and Vulkan application development. <br/>
- It provides a simple platform-indepent api for creating window, contexts and surface, reading input, handling input, etc. <br/>

> OpenGL -> Double Buffering <br/>
> VLC, YOUTUBE -> Frame Buffering <br/>
> Operating system -> Compositor Buffering <br/>
> Mobile screen -> SurfaceFlinger & FrameBuffer <br/>
> Games -> Double/Triple Buffering with Vsync <br/>

# Get Started <br/>
1. **Include GLFW header** <br/>
```c
#include <glad/gl.h>
#include <GLFW/glfw3.h>
```
- It includes the OpenGL header from development environment. <br/>
- Provides all constants, types and function. <br/>
- include `<glad/gl.h>` first: provides all OpenGL function declarations.
<br/>
***
**How OpenGL function loading works in modern OpenGL development** <br/>
- function are not directly available through compiler, OpenGL is implemented by graphic driver, and function pointers needs to dynamically load at runtime. <br/>
- It needs OpenGl context to store thinks like `Buffers`, `Shaders & Programs`, `Texture` or any other opengl-related states, objects and resource. <br/>
- We need windowing system or library like GLFW, SDL, X11, to create context. <br/>
- We need extension loader library like `GLAD`, `GLEW`, `GL3W` etc to access OpenGL functions. <br/>
<br/>

2. **Initialize GLFW** *(before creating opengl context)*
```c
glfwInit();
```
- It loads platform specific api: in window `win32api`, `x11` or `wayand` in linux, macOS `cocoa API`.
- It reads connected monitors and stores their resolution, refresh rate and properties.
- Sets up timers.
- RETURN `GLFW_TRUE`(1) if success, otherwise RETURN `GLFW_FALSE`(0)

3. **Create a window** *(creates opengl context automatically)* <br/>
- GLFWAPI GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share); <br/>
- unsuccessful: return NULL, successful return pointer to `GLFWwindow` <br/>
- `GLFWAPI` ensures proper function exporting/importing for GLFW when compiling as a shared library `.dll` in window, `.so` in linux and `.dylib` on macOS <br/>

```c
GLFWwindow* window = glfwCreateWindow(800, 600, "PENGER WORLD", NULL, NULL);
// full screen window
GLFWwindow* window = glfwCreateWindow(800, 600, "PENGER WORLD", glfwGetPrimaryMonitor(), NULL);
if (!window) {
	glfwTerminate();
	return -1;
}
```

4. **Custom window with `glfwWindowHint()`** <br/>
- Used before creating a window. <br/>
- Used to set various Window and Context options like *major* and *minor* version, *core/compatibility*, *resizing*, *hidden*, *transparent*, *ani-aliasing*. <br/>
```c
// syntax
void glfwWindowHint(int hint, int value);

//example
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
```
- `hint`: setting to change. <br/>
- `value`: value to assign. <br/>

5. **Window destruction** <br/>
- window is destroyed <br/>
```c
glfwDestroyWindow(window);
```

6. **Setting OpenGL context** <br/>
- Makes the OpenGL context of the specified window current on the current thread. <br/>
- only one window context can be active at time per thread <br/>
```c
// rexd 525
glfwMakeContextCurrent(window);
```
> Other related function <br/>
> glfwSwapInterval(int interval): frame swap delay *V-Sync* <br/>
> glfwGetProcAddress(const char* procname): load function pointer dynamically <br/>
7. **Buffer Swapping** <br/>
> FrameBuffer is complete set of color, depth(3D rendering) and stencil(masking operation) buffers that opengl renders. <br/>

- It is by default double buffered. i.e. there are 2 renderable buffers front and back buffer. <br/>
- front buffer is the one being displayed <br/>
- back buffer the one you render to <br/>
- when entire frame has be rendered, it is time to swap the back and front buffers, meaning it switchs pointers <br/>

```c
// syntax
glfwSwapBuffers(window);

while (!glfwWindowShouldClose(window)) {

  glClear(GL_COLOR_BUFFER_BIT); // Render to the back buffer

  glfwSwapBuffers(window); // Swap the buffers

  glfwPollEvents(); // Handle events
}
```

> Games can have 3 buffers front, back 1, back 2. which reduce VSync stutter

## The Render Flow
1. Clear the back buffer *(glClear(GL_COLOR_BUFFER_BIT))* <br/>
2. Render everything (images, shapes, text, etc) <br/>
3. Swap buffers *(glfwSwapBuffers(window))* <br/>
4. Repeat <br/>

## How Does Multi-threading Work in OpenGL?
- Each thread per context. <br/>
- sharing resources between contexts (textures, shaders, etc) <br/>
- one thread per window for rendering <br/>

## Approach for Multi-threading
- One Window, One Render Thread <br/>
- Multiple Windows, Multiple Render Thread <br/>
- Multiple Windows, Shared Context <br/>
