TEMPLATE = app
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lglfw3 -lGL -lGLEW -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -lopenal

SOURCES += main.cpp \
    utils/Log.cpp \
    al/ALBuffer.cpp \
    al/ALCreateSample.cpp \
    al/ALDevice.cpp \
    al/ALError.cpp \
    al/ALListener.cpp \
    al/ALOggSample.cpp \
    al/ALSample.cpp \
    al/ALSource.cpp \
    al/ALWavSample.cpp \
    AudioSystem.cpp \
    utils/StringUtils.cpp \
    utils/Error.cpp

HEADERS += \
    stb_vorbis.h \
    utils/Log.hpp \
    utils/Singleton.hpp \
    al/ALBuffer.hpp \
    al/ALCreateSample.hpp \
    al/ALDevice.hpp \
    al/ALError.hpp \
    al/ALListener.hpp \
    al/ALOggSample.hpp \
    al/ALPositionSource.hpp \
    al/ALSample.hpp \
    al/ALSource.hpp \
    al/ALSourceBase.hpp \
    al/ALWavSample.hpp \
    AudioSystem.hpp \
    utils/Debug.hpp \
    utils/Exception.hpp \
    utils/StringUtils.hpp \
    utils/Error.hpp \
    utils/NonCopyable.hpp
