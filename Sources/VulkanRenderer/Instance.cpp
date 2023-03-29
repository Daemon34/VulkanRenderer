#include "Instance.hpp"
#include "ValidationLayers.hpp"
#include <stdexcept>

void Instance::createInstance(ValidationLayers validationLayers) {
    if (validationLayers.isValidationLayerEnable() && !validationLayers.checkValidationLayerSupport()) {
        throw std::runtime_error("Validation layers request, but not available !");
    }

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    auto extensions = getRequiredExtensions(validationLayers);
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
    if (validationLayers.isValidationLayerEnable()) {
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.validationLayersName.size());
        createInfo.ppEnabledLayerNames = validationLayers.validationLayersName.data();

        validationLayers.populateDebugMessengerCreateInfo(debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
    }
    else {
        createInfo.enabledLayerCount = 0;

        createInfo.pNext = nullptr;
    }

    if (vkCreateInstance(&createInfo, nullptr, getVulkanInstancePtr()) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create instance !");
    }
}

std::vector<const char*> Instance::getRequiredExtensions(ValidationLayers validationLayers) {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

    if (validationLayers.isValidationLayerEnable()) {
        extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    }

    return extensions;
}

VkInstance* Instance::getVulkanInstancePtr() {
    return &instance;
};