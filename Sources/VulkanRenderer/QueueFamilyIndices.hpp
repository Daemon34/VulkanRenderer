#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <optional>

class QueueFamilyIndices
{
public:
	static QueueFamilyIndices findQueueFamilies(const VkPhysicalDevice& device, const VkSurfaceKHR& surface);

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }

    std::optional<uint32_t> getGraphicsFamily();
    std::optional<uint32_t> getPresentFamily();

    void setGraphicsFamily(std::optional<uint32_t> value);
    void setPresentFamily(std::optional<uint32_t> value);

private:
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
};

