#include <Dunjun/common.hpp>
#include <GL/Glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

static const int g_windowWidth = 800;
static const int g_windowHeight = 600;

int main()
{

	if (!glewInit())
		return EXIT_FAILURE;

	GLFWwindow* window;

	if (!glfwInit())
		return EXIT_FAILURE;

	window = glfwCreateWindow(g_windowWidth, g_windowHeight, "Dunjun", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);

	float vertices[] = {
		0.0f, 0.5f,
	   -0.5f, -0.5f,
		0.5f, -0.5f
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	bool running = true;
	bool fullscreen = false;

	while (running)
	{
		glClearColor(0.f, 0.69f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwWindowShouldClose(window))
			running = false;

		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			running = false;

		if (glfwGetKey(window, GLFW_KEY_F11))
		{
			fullscreen = !fullscreen;
			GLFWwindow* newWindow;

			if (fullscreen)
			{
				int count;
				const GLFWvidmode* modes =  glfwGetVideoModes(glfwGetPrimaryMonitor(), &count);
				newWindow = glfwCreateWindow(modes[count-1].width, modes[count-1].height, "Dunjun", glfwGetPrimaryMonitor(), window);
			}
			else
			{
				newWindow = glfwCreateWindow(g_windowWidth, g_windowHeight, "Dunjun", nullptr, window);
			}
				
			glfwDestroyWindow(window);
			window = newWindow;
			glfwMakeContextCurrent(window);
		}
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return EXIT_SUCCESS;
}