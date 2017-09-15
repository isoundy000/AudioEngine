#ifndef ALDEVICE_HPP
#define ALDEVICE_HPP

#include <iostream>
#include <glm/glm.hpp>

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>

#include "utils/Log.hpp"

namespace audio
{
namespace al
{

/// OpenAL audio backend. Class initilize openal device and create context.
class Device
{
public:

    Device();
    virtual ~Device();

    /// Return true if device was initialize.
    bool isInitialized();

private:

    /// Pointer to ALCdevice structure. NULL is failure.
    static ALCdevice *m_device;

    /// Pointer to ALCcontext structure. NULL is failure.
    static ALCcontext *m_context;

    /// This flag is for control initialize openal device and context.
    /// Flag inhibiting for multi initilize openal device and context.
    static bool m_isInitialized;

    /// Counter count number of initialize.
    static int m_counter_inits;
};

} // namespace audio::al
} // namespace al

#endif
