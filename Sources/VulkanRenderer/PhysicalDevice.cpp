#include "PhysicalDevice.hpp"
#include <stdexcept>
#include <vector>
#include <optional>
#include "QueueFamilyIndices.hpp"
#include <set>
#include "SwapChainSupportDetails.hpp"

void PhysicalDevice::pickPhysicalDevice(const VkInstance& instance, const VkSurfaceKHR& surface) {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw std::runtime_error("Failed to find GPUs with Vulkan Support !");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    for (const auto& device : devices) {
        if (isDeviceSuitable(device, surface)) {
            _physicalDevice = device;
            break;
        }
    }

    if (_physicalDevice == VK_NULL_HANDLE) {
        throw std::runtime_error("Failed to find a suitable GPU !");
    }
}

bool PhysicalDevice::isDeviceSuitable(const VkPhysicalDevice& physicalDevice, const VkSurfaceKHR& surface) {
    QueueFamilyIndices indices = QueueFamilyIndices::findQueueFamilies(physicalDevice, surface);

    bool extensionsSupported = checkDeviceExtensionSupport(physicalDevice);

    bool swapChainAdequate = false;
    if (extensionsSupported) {
        SwapChainSupportDetails swapChainSupport = SwapChainSupportDetails::querySwapChainSupport(physicalDevice, surface);
        swapChainAdequate = !swapChainSupport.getSurfaceFormats().empty() && !swapChainSupport.getSurfacePresentModes().empty();
    }

    VkPhysicalDeviceFeatures supportedFeatures;
    vkGetPhysicalDeviceFeatures(physicalDevice, &supportedFeatures);

    return indices.isComplete() && extensionsSupported && swapChainAdequate && supportedFeatures.samplerAnisotropy;
}

bool PhysicalDevice::checkDeviceExtensionSupport(const VkPhysicalDevice& physicalDevice) {
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, availableExtensions.data());

    std::set<std::string> requiredExtensions(_deviceExtensions.begin(), _deviceExtensions.end());

    for (const auto& extension : availableExtensions) {
        requiredExtensions.erase(extension.extensionName);
    }

    return requiredExtensions.empty();
}

VkPhysicalDevice PhysicalDevice::getVulkanPhysicalDevice() {
    return _physicalDevice;
}

std::vector<const char*>* PhysicalDevice::getRequiredExtensionsPtr() {
    return &_deviceExtensions;
}