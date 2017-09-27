#ifndef ALOGGSAMPLE_H
#define ALOGGSAMPLE_H

#include "ALSample.hpp"

namespace audio
{
namespace al
{

/// Class represent load ogg files and decode ogg files.
class OggSample : public Sample
{
public:

    OggSample();
    OggSample(const std::string &path);
    virtual ~OggSample();

private:

    /// Number of channels in ogg file.
    int m_channels;

    /// Sample frequency ogg file. Usually 44100hz.
    unsigned int m_sampleRate;

    /// Total time ogg file in ms.
    float m_duration;

    /// Return code from stb_vorbis.
    int m_error;
};

} // namespace audio::al
} // namespace al

#endif
