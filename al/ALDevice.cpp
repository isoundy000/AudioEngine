#include "ALDevice.hpp"

namespace audio
{
namespace al
{

// initialize static member
bool Device::m_isInitialized = false;
// Count of initialize
int Device::m_counter_inits = 0;
// openal device
ALCdevice *Device::m_device = nullptr;
// openal context
ALCcontext *Device::m_context = nullptr;

Device::Device()
{
    if(!m_isInitialized)
    {
        m_device = alcOpenDevice(nullptr);
        if (!m_device)
        {
            LOG("Cannot open a device");
            m_isInitialized = false;
        }
        else
        {
            const char *device = alcGetString(m_device, ALC_DEVICE_SPECIFIER);
            LOG("OpenAL device   : " + std::string(device));

        }

        m_context = alcCreateContext(m_device, nullptr);
        if (m_context == nullptr || alcMakeContextCurrent(m_context) == ALC_FALSE)
        {
            if (m_context != nullptr)
            {
                alcDestroyContext(m_context);
            }

            alcCloseDevice(m_device);
            LOG("Cannot set an context! Closing device ...");
            m_isInitialized = false;
        }
        else
        {
            const char *version = alGetString(AL_VERSION);
            const char *renderer = alGetString(AL_RENDERER);
            const char *vendor = alGetString(AL_VENDOR);

            LOG("OpenAL version  : " + std::string(version));
            LOG("OpenAL renderer : " + std::string(renderer));
            LOG("OpenAL vendor   : " + std::string(vendor));
            LOG("OpenAL init done");
        }
        m_isInitialized = true;
    }

    m_counter_inits++;
    //std::cerr << "Create: " << m_counter_initits << std::endl;
}

Device::~Device()
{
    //std::cerr << "Destroy: " << m_counter_initits << std::endl;
    m_counter_inits--;

    if(!m_counter_inits)
    {
        if (m_context)
        {
            alcMakeContextCurrent(nullptr);
            alcDestroyContext(m_context);
            m_context = nullptr;
            LOG("Destroy openal context");
        }

        if (m_device)
        {
            alcCloseDevice(m_device);
            m_device = nullptr;
            LOG("Closed openal device");
        }
    }
}

bool Device::isInitialized()
{
    return  m_isInitialized;
}

} // namespace audio::al
} // namespace al
