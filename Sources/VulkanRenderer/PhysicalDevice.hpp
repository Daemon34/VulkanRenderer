#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vector>

class PhysicalDevice
{
public:
	void pickPhysicalDevice(const VkInstance& instance, const VkSurfaceKHR& surface);

	bool isDeviceSuitable(const VkPhysicalDevice& physicalDevice, const VkSurfaceKHR& surface);

	bool checkDeviceExtensionSupport(const VkPhysicalDevice& physicalDevice);

	VkPhysicalDevice getVulkanPhysicalDevice();

	std::vector<const char*>* getRequiredExtensionsPtr();

private:
	VkPhysicalDevice _physicalDevice = VK_NULL_HANDLE;

	std::vector<const char*> _deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
};

