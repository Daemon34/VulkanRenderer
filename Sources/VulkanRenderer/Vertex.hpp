#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <array>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>

class Vertex
{
public:
    static VkVertexInputBindingDescription getBindingDescription();

    static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions();

    glm::vec3 getVertexPosition() {
        return _pos;
    };

    glm::vec3 getVertexColor() {
        return _color;
    };

    glm::vec2 getVertexTexCoord() {
        return _texCoord;
    };

    bool operator==(const Vertex& other) const {
        return (_pos == other._pos && _color == other._color && _texCoord == other._texCoord);
    }

    glm::vec3 _pos;
    glm::vec3 _color;
    glm::vec2 _texCoord;
};

namespace std {
    template<> struct hash<Vertex> {
        size_t operator()(Vertex const& vertex) const {
            return ((hash<glm::vec3>()(vertex._pos) ^
                (hash<glm::vec3>()(vertex._color) << 1)) >> 1) ^
                (hash<glm::vec2>()(vertex._texCoord) << 1);
        }
    };
}

