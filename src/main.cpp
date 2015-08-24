#include <Dunjun/common.hpp>
#include <GLFW/glfw3.h>

#include <iostream>

static const int g_windowWidth = 800;
static const int g_windowHeight = 600;

int main()
{
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
				newWindow = glfwCreateWindow(modes[count - 1].width, modes[count - 1].height, "Dunjun", glfwGetPrimaryMonitor(), window);
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