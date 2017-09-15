#include <iostream>
#include "AudioSystem.hpp"

audio::al::Listener *g_listener;
audio::al::AudioSystem *g_audioSystem;

void loadAudio()
{
    g_audioSystem = new audio::al::AudioSystem();
    g_listener = new audio::al::Listener();

    g_audioSystem->loadFromFile("thunder","resource/thunder2_mono.wav");
    g_audioSystem->loadFromFile("radio", "resource/radio_mono.wav");


    std::shared_ptr<audio::al::Source> source_thunder = g_audioSystem->getSource("thunder");
    source_thunder->setPosition(glm::vec3(5.0f, 0.0f, 5.0f));
    source_thunder->setDirection(glm::vec3(-5.0f, -5.0f, 0.0f));
    source_thunder->setGain(8.0f);
    source_thunder->enableLoop(true);
    source_thunder->enableRelativeListener(false);
    source_thunder->setMinMaxDistance(0.0f, 0.2f);
    source_thunder->play();

    std::shared_ptr<audio::al::Source> source_radio = g_audioSystem->getSource("radio");
    source_radio->setPosition(glm::vec3(2.5f, 2.5f, -13.5f));
    source_radio->setGain(12.0f);
    source_radio->enableLoop(true);
    source_radio->enableRelativeListener(false);
    source_radio->setMinMaxDistance(0.0f, 2.0f);
    source_radio->play();
}

void updateListener()
{
    g_listener->updateListenerPosition(glm::vec3(0.0,0.0,0.0),
            glm::vec3(0.0,0.0,0.0));
}

void cleanupAudio()
{
    delete g_audioSystem;
    delete g_listener;
}

int main()
{
    loadAudio();
    cleanupAudio();
    return 0;
}
