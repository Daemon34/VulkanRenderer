#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include "defines.hpp"
#include <array>

class Vertex
{
public:
    static VkVertexInputBindingDescription getBindingDescription();

    static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();

    glm::vec2 getVertexPosition() {
        return _pos;
    };

    glm::vec3 getVertexColor() {
        return _color;
    };

    glm::vec2 getVertexTexCoord() {
        return _texCoord;
    };

    glm::vec2 _pos;
    glm::vec3 _color;
    glm::vec2 _texCoord;
};

