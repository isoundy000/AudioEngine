#ifndef AUDIOSYSTEM_HPP
#define AUDIOSYSTEM_HPP

#include "al/ALListener.hpp"
#include "al/ALSource.hpp"
#include "utils/Singleton.hpp"

#include <unordered_map>
#include <vector>

namespace audio
{
namespace al
{

/// Collects various settings of the audio system.
class AudioSystemSettings
{
public:

    /// Default value for every sound.
    float master_gain = 1.0f;

    /// Default listener gain.
    float listener_gain = 1.0f;

    /// Doppler factor is a simple scaling of source and listener velocities
    /// to exaggerate or deemphasize the Doppler (pitch).
    float doppler_factor = 1.0f;

    /// Default value for speed of sound for every sound.
    float speed_of_sound = 343.3f;
};

class AudioSystem : public Singleton<AudioSystem> {
public:

    AudioSystem();
    AudioSystem(const AudioSystemSettings &settings);
    ~AudioSystem();

    /// Sound file is load from file with his "name".
    void loadFromFile(const std::string &name, const std::string &file);

    /// Find source and return.
    std::shared_ptr<Source> getSource(const std::string &name);

    /// Update all sources in audio system.
    //void update();

private:

    /// Basic setting for audio system.
    AudioSystemSettings m_settings;

    /// All decoded sources in audio system.
    std::unordered_map<std::string, std::shared_ptr<Source>> m_decoded_sources;

    /// Default value for listener gain
    float m_listener_gain;

    /// Default value for sound gain
    float m_sound_gain;

    /// Default value for doppler factor
    float m_doppler_factor;

    /// Default value speed of sound
    float m_speed_of_sound;
};

} // namespace audio::al
} // namespace al

#endif // AUDIOSYSTEM_HPP
