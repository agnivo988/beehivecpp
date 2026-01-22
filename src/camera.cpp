#include "../include/camera.h"
#include <glm/gtc/matrix_transform.hpp>

glm::mat4 Camera::getView() {
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    return glm::lookAt(pos, pos + glm::normalize(front), {0,1,0});
}
