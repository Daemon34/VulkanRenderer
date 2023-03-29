#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "ValidationLayers.hpp"

class Instance
{
public:
	void createInstance(ValidationLayers validationLayers);

	std::vector<const char*> getRequiredExtensions(ValidationLayers validationLayers);

	VkInstance* getVulkanInstancePtr();

private:
	VkInstance instance;
};

