#ifndef ALSAMPLE_HPP
#define ALSAMPLE_HPP

#include <memory>
#include "ALBuffer.hpp"

namespace audio
{
namespace al
{

/// Class represent audio sample.
class Sample : public Buffer
{
public:

    Sample();
    virtual ~Sample();

    /// Convert from OpenAL format to count of channels.
    /// \param output OpenAL format channels.
    ALuint getFormatNumChannels(ALuint channels);
};

} // namespace audio::al
} // namespace al

#endif
