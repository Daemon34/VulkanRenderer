#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

class ValidationLayers
{
public:
	bool checkValidationLayerSupport();

	const std::vector<const char*> validationLayersName = {
		"VK_LAYER_KHRONOS_validation"
	};

    static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
        VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
        VkDebugUtilsMessageTypeFlagsEXT messageType,
        const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
        void* pUserData);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    void setupDebugMessenger(const VkInstance& instance);

    VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator,
        VkDebugUtilsMessengerEXT* pDebugMessenger);

    void DestroyDebugUtilsMessengerEXT(VkInstance instance, const VkAllocationCallbacks* pAllocator);

    const bool isValidationLayerEnable();

    VkDebugUtilsMessengerEXT getDebugMessenger();

private:
    #ifdef NDEBUG
            const bool enableValidationLayers = false;
    #else
            const bool enableValidationLayers = true;
    #endif
    VkDebugUtilsMessengerEXT debugMessenger;
};

