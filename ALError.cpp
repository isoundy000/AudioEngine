#include "ALError.hpp"
#include <string>

std::string al_error_string(int errorCode)
{
    switch (errorCode)
    {
        case AL_INVALID_ENUM:       return std::string("An invalid enum value was passed to an OpenAL function");
        case AL_INVALID_VALUE:      return std::string("An invalid value was passed to an OpenAL function");
        case AL_INVALID_OPERATION:  return std::string("The requested operation is not valid");
        case AL_INVALID_NAME:       return std::string("A bad name (ID) was passed to an OpenAL function");
        case AL_OUT_OF_MEMORY:      return std::string("The requested operation resulted in OpenAL running out of memory");
        default:                    return std::string("Unknown OpenAL error: " + std::to_string(errorCode));
    }
}
