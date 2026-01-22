#include <glm/glm.hpp>
#include <cmath>

glm::vec3 beePosition(int id, float t)
{
    return {
        sin(t + id) * 3.0f,
        cos(t * 1.5f + id),
        cos(t + id) * 3.0f
    };
}
