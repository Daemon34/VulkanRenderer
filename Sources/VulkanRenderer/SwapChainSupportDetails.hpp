#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#pragma once
#include <vector>

class SwapChainSupportDetails
{
public:
    static SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, const VkSurfaceKHR& surface);

    VkSurfaceCapabilitiesKHR getSurfaceCapabilities();
    std::vector<VkSurfaceFormatKHR> getSurfaceFormats();
    std::vector<VkPresentModeKHR> getSurfacePresentModes();

private:
    VkSurfaceCapabilitiesKHR _capabilities;
    std::vector<VkSurfaceFormatKHR> _formats;
    std::vector<VkPresentModeKHR> _presentModes;
};

