#ifndef ALLISTENER_HPP
#define ALLISTENER_HPP

#include "ALPositionSource.hpp"

namespace audio
{
namespace al
{

class Listener : public PositionSource
{

public:

    Listener();
    virtual ~Listener();

    /// Set vector position listener
    void setPosition(const glm::vec3 &position);
    void setPosition(const float &x, const float &y, const float &z);

    /// Set vector velocity listener
    void setVelocity(const glm::vec3 &velocity);
    void setVelocity(const float &x, const float &y, const float &z);

    /// Set vector direction listener
    void setDirection(const glm::vec3 &direction);
    void setDirection(const float &x, const float &y, const float &z);

    /// Get vector position listener
    glm::vec3 getPosition();

    /// Get vector velocity listener
    glm::vec3 getVelocity();

    /// Update every second position and direction listener
    void updateListenerPosition(const glm::vec3 &pos, const glm::vec3 &dir);

private:

    /// Position listener in 3d space
    glm::vec3 m_position;

    /// Velocity listener in 3d space
    glm::vec3 m_velocity;

    /// Direction listener in 3d space
    glm::vec3 m_direction;

    /// Up vector listener in 3d space
    glm::vec3 m_up_vector;
};

} // namespace audio::al
} // namespace al

#endif
