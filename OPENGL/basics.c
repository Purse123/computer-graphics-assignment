#include <GL/gl.h>
#include <GLFW/glfw3.h>

int main() {
  if (!glfwInit()) {
    /*
      const char* description;
      int code = glfwGetError(&description);
      if (description) {
        printf("GLFW Error (%d): %s\n", code, description);
      }
      else {
        printf("GLFW Error (%d): Unknown error\n", code);
      }
    */
    return -1;
  }

  GLFWwindow* window = glfwCreateWindow(600, 400, "Tero bau", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwTerminate();
  return 0;
}
