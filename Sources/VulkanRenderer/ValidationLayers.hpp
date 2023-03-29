#pragma once
#include <vector>

class ValidationLayers
{
public:
	bool checkValidationLayerSupport();

	const std::vector<const char*> validationLayersName = {
		"VK_LAYER_KHRONOS_validation"
	};
};

