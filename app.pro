QT += core gui widgets multimedia sql

TARGET = group10 
TEMPLATE = app
CONFIG += c++11

SOURCES += \
    $$PWD/src/*.cpp

HEADERS += \
    $$PWD/include/*.h

OTHER_FILES += \
    $$PWD/fx/*.wav \
    $$PWD/sql/Dockerfile \
    $$PWD/docker-compose.yml \
    $$PWD/Dockerfile