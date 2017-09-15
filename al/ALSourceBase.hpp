#ifndef ALSOURCEBASE_HPP
#define ALSOURCEBASE_HPP

#include "glm/glm.hpp"

namespace audio
{
namespace al
{

class SourceBase
{
public:

    /// Play sound according to sound id.
    virtual void play() = 0;

    /// Stop sound according to sound id.
    virtual void stop() = 0;

    /// Pause sound according to sound id.
    virtual void pause() = 0;

    virtual void setPosition(const glm::vec3 &position) = 0;
    virtual void setPosition(const float &x, const float &y, const float &z) = 0;
    virtual void setVelocity(const glm::vec3 &velocity) = 0;
    virtual void setVelocity(const float &x, const float &y, const float &z) = 0;
    virtual void setDirection(const glm::vec3 &direction) = 0;
    virtual void setDirection(const float &x, const float &y, const float &z) = 0;
};

} // namespace audio::al
} // namespace al

#endif
