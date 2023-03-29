#include "Window.hpp"

#include "defines.hpp";
#include <stdexcept>

void Window::initWindow() {
    // Initialize GLFW library
    glfwInit();

    // Avoid to create an OpenGL context since we are using Vulkan
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a Window named Vulkan, without specifying on which monitor. The last parameter is only for OpenGL so we don't need it
    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Window::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto appWindow = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
    appWindow->framebufferResized = true;
}

void Window::createSurface(const VkInstance& instance) {
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface !");
    }
}

GLFWwindow* Window::getGLFWwindowPtr() {
    return window;
}

bool Window::isFrameBufferResized() {
    return framebufferResized;
}

void Window::setFrameBufferResized(bool value) {
    framebufferResized = value;
}

VkSurfaceKHR* Window::getSurfacePtr() {
    return &surface;
}