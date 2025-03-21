#include <GLFW/glfw3.h>
#include <GL/gl.h>

int main() {
  if (!glfwInit()) {
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
