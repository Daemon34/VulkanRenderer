#include "QueueFamilyIndices.hpp"
#include <vector>

QueueFamilyIndices QueueFamilyIndices::findQueueFamilies(const VkPhysicalDevice& device, const VkSurfaceKHR& surface) {
    QueueFamilyIndices indices;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int indicesIndex = 0;
    for (const auto& queueFamily : queueFamilies) {
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.setGraphicsFamily(indicesIndex);
        }

        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, indicesIndex, surface, &presentSupport);

        if (presentSupport) {
            indices.setPresentFamily(indicesIndex);
        }

        if (indices.isComplete()) {
            break;
        }

        indicesIndex++;
    }
    return indices;
}

std::optional<uint32_t> QueueFamilyIndices::getGraphicsFamily() {
    return graphicsFamily;
}

std::optional<uint32_t> QueueFamilyIndices::getPresentFamily() {
    return presentFamily;
}

void QueueFamilyIndices::setGraphicsFamily(std::optional<uint32_t> value) {
    graphicsFamily = value;
}

void QueueFamilyIndices::setPresentFamily(std::optional<uint32_t> value) {
    presentFamily = value;
}