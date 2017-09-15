#include "AudioSystem.hpp"

namespace audio
{
namespace al
{

AudioSystem::AudioSystem() :
    //m_default_listener_gain(m_settings.default_listener_gain)
    //m_sound_gain(m_settings.sound_gain),
    m_listener_gain(m_settings.doppler_factor),
    m_speed_of_sound(m_settings.speed_of_sound)
{

}

AudioSystem::AudioSystem(const AudioSystemSettings &settings) :
    //m_sound_gain(settings.sound_gain),
    m_listener_gain(settings.doppler_factor),
    m_speed_of_sound(settings.speed_of_sound)
{

}

AudioSystem::~AudioSystem()
{

}

void AudioSystem::loadFromFile(const std::string &name, const std::string &file)
{
   if(!file.empty())
   {
       std::shared_ptr<Source> source = std::make_shared<Source>();
       source->loadFromFile(file);
       m_decoded_sources.insert(std::pair<std::string, std::shared_ptr<Source>>(name, source));
   }
   else
   {
       std::cout << "File path is empty!" << std::endl;
   }
}

std::shared_ptr<Source> AudioSystem::getSource(const std::string &name)
{
    auto found_source = m_decoded_sources.find(name);
    if(found_source != m_decoded_sources.end())
    {
        return found_source->second;
    }

    std::cout << "Invalid source , source not found." << std::endl;
}

} // namespace audio::al
} // namespace al
