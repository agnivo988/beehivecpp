#pragma once
#include <glm/glm.hpp>

class Camera {
public:
    glm::vec3 pos{0, 0, 8};
    float yaw{-90}, pitch{0};

    glm::mat4 getView();
};
