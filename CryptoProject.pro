QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    T4_AES.cpp \
    T4_DES.cpp \
    T4_RSA.cpp \
    T4_caesar.cpp \
    T4_columnar.cpp \
    T4_hillcipher.cpp \
    T4_md5.cpp \
    T4_monoalphabetic.cpp \
    T4_playfair.cpp \
    T4_railfence.cpp \
    T4_vigenereautokey.cpp \
    T4_vigenererepeatingkey.cpp \
    main.cpp \
    mainwindow.cpp \
    qtaes.cpp \
    qtcaesar.cpp \
    qtcolumnar.cpp \
    qtdes.cpp \
    qthill.cpp \
    qtmd5.cpp \
    qtmonoalphabetic.cpp \
    qtplayfair.cpp \
    qtrailfence.cpp \
    qtrsa.cpp \
    qtvigenereautokey.cpp \
    qtvigenererepeatingkey.cpp

HEADERS += \
    T4_AES.h \
    T4_DES.h \
    T4_RSA.h \
    T4_caesar.h \
    T4_columnar.h \
    T4_hillcipher.h \
    T4_md5.h \
    T4_monoalphabetic.h \
    T4_playfair.h \
    T4_railfence.h \
    T4_vigenereautokey.h \
    T4_vigenererepeatingkey.h \
    mainwindow.h \
    qtaes.h \
    qtcaesar.h \
    qtcolumnar.h \
    qtdes.h \
    qthill.h \
    qtmd5.h \
    qtmonoalphabetic.h \
    qtplayfair.h \
    qtrailfence.h \
    qtrsa.h \
    qtvigenereautokey.h \
    qtvigenererepeatingkey.h

FORMS += \
    mainwindow.ui \
    qtaes.ui \
    qtcaesar.ui \
    qtcolumnar.ui \
    qtdes.ui \
    qthill.ui \
    qtmd5.ui \
    qtmonoalphabetic.ui \
    qtplayfair.ui \
    qtrailfence.ui \
    qtrsa.ui \
    qtvigenereautokey.ui \
    qtvigenererepeatingkey.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
