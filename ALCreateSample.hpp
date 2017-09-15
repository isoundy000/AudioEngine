#ifndef ALCREATESAMPLE_HPP
#define ALCREATESAMPLE_HPP

#include <memory>
#include <iostream>

#include "utils/Exception.hpp"
#include "ALWavSample.hpp"
#include "ALOggSample.hpp"

namespace audio
{
namespace al
{

// Function create sample according to sound file extension.
std::shared_ptr<Sample> createSample(const std::string &path);

} // namespace audio::al
} // namespace al

#endif
