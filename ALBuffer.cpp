#include "ALBuffer.hpp"

namespace audio
{
namespace al
{

Buffer::Buffer()
{
    alGenBuffers(1, &m_buffer);
    LOG("Generated buffer");
}

Buffer::~Buffer()
{
    alDeleteBuffers(1, &m_buffer);

    LOG("Deleted buffer");
}

ALuint Buffer::getBuffer()
{
    return m_buffer;
}

} // namespace audio::al
} // namespace al
