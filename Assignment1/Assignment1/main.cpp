#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	// Initialize GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Initialialize window title and size
	int width = 800;
	int height = 600;
    char title[] = "Assignment 1";

	// Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

	// Load OpenGL function pointers with GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

	// Set the viewport
    glViewport(0, 0, width, height);

	// Register a callback function to adjust the viewport when the window is resized
    void framebuffer_size_callback(GLFWwindow * window, int width, int height);

	// Register the callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Render loop
    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	// Clean up and exit
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
