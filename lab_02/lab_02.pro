TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    $$PWD/Iterator/base_iterator.h \
    $$PWD/Vector/base_vector.h \
    $$PWD/Iterator/const_iterator.h \
    $$PWD/Iterator/const_iterator.hpp \
    $$PWD/Exception/errors.h \
    $$PWD/Iterator/iterator.h \
    $$PWD/Iterator/iterator.hpp \
    $$PWD/Vector/vector.h \
    $$PWD/Vector/vector.hpp
