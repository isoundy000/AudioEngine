#ifndef ALPOSITIONSOURCE_HPP
#define ALPOSITIONSOURCE_HPP

#include "ALDevice.hpp"

namespace audio
{
namespace al
{

class PositionSource : public Device
{

public:

    PositionSource() { }
    virtual ~PositionSource() { }

    /// Set postion vector positionsource
    virtual void setPosition(const glm::vec3 &position) = 0;
    virtual void setPosition(const float &x, const float &y, const float &z) = 0;

    /// Set velocity vector positionsource
    virtual void setVelocity(const glm::vec3 &velocity) = 0;
    virtual void setVelocity(const float &x, const float &y, const float &z) = 0;

    /// Set direction vector positionsource
    virtual void setDirection(const glm::vec3 &direction) = 0;
    virtual void setDirection(const float &x, const float &y, const float &z) = 0;

    /// Return vec3 source position
    virtual glm::vec3 getPosition() = 0;

    /// Return vec3 source velocity
    virtual glm::vec3 getVelocity() = 0;
};

} // namespace audio::al
} // namespace al

#endif
