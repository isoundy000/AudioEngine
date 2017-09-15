#ifndef ALERROR_HPP
#define ALERROR_HPP

#include <iostream>
#include "AL/al.h"

namespace audio
{
namespace al
{

/// Return conveted openal error number to std::string
std::string al_error_string(int errorCode);

/// Macro for check openal error
#define AL_ERROR_CHECK                                       \
{                                                            \
    ALenum error = alGetError();                             \
    if (error != AL_NO_ERROR)                                \
    {                                                        \
        std::string errstr = al_error_string(error);         \
        LOG("Warning: Catch openal error code : " + errstr); \
    }                                                        \
}

} // namespace audio::al
} // namespace al

#endif
