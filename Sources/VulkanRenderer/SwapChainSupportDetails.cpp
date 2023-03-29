#include "SwapChainSupportDetails.hpp"

SwapChainSupportDetails SwapChainSupportDetails::querySwapChainSupport(VkPhysicalDevice device, const VkSurfaceKHR& surface) {
    SwapChainSupportDetails details;

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, surface, &details._capabilities);

    uint32_t formatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, nullptr);

    if (formatCount != 0) {
        details._formats.resize(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface, &formatCount, details._formats.data());
    }

    uint32_t presentationModeCount;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationModeCount, nullptr);

    if (presentationModeCount != 0) {
        details._presentModes.resize(presentationModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, surface, &presentationModeCount, details._presentModes.data());
    }

    return details;
}

VkSurfaceCapabilitiesKHR SwapChainSupportDetails::getSurfaceCapabilities()
{
    return _capabilities;
}

std::vector<VkSurfaceFormatKHR> SwapChainSupportDetails::getSurfaceFormats()
{
    return _formats;
}

std::vector<VkPresentModeKHR> SwapChainSupportDetails::getSurfacePresentModes()
{
    return _presentModes;
}
