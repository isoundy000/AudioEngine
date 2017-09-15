#include "ALCreateSample.hpp"

namespace audio
{
namespace al
{

std::shared_ptr<Sample> createSample(const std::string &path)
{

    if(path.rfind(".wav") == path.size() - 4)
    {
        return std::make_shared<WavSample>(path);
    }
    else if(path.rfind(".ogg") == path.size() - 4)
    {
        return std::make_shared<OggSample>(path);
    }

    Throw(InvalidArgument,
        strprintf("only .wav or .ogg files are currently supported, got '%s'", path.c_str()));
}

} // namespace audio::al
} // namespace al
