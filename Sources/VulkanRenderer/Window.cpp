#include "Window.hpp"

#include "defines.hpp";

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

GLFWwindow* Window::getGLFWwindowPtr() {
    return window;
}

bool Window::isFrameBufferResized() {
    return framebufferResized;
}

void Window::setFrameBufferResized(bool value) {
    framebufferResized = value;
}