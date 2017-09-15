#ifndef ALBUFFER_HPP
#define ALBUFFER_HPP

#include "ALDevice.hpp"
#include "ALError.hpp"

namespace audio
{
namespace al
{

/// Class initialize OpenAL device only one and
/// generate for every sound buffer id.
class Buffer
{
public:

    /// Default constructor.
    Buffer();
    virtual ~Buffer();

    // Gets actual buffer id.
    ALuint getBuffer();

public:

    /// Buffer id
    ALuint m_buffer;
};

} // namespace audio::al
} // namespace al

#endif
