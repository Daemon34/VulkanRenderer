#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class VulkanRendererApplication;

class Window
{
public:
	void initWindow();

	static void framebufferResizeCallback(GLFWwindow* window, int width, int height);

	void createSurface(const VkInstance& instance);

	GLFWwindow* getGLFWwindowPtr();

	bool isFrameBufferResized();

	void setFrameBufferResized(bool value);

	VkSurfaceKHR* getSurfacePtr();

private:
	GLFWwindow* window;
	bool framebufferResized = false;
	VkSurfaceKHR surface;
};

