#-------------------------------------------------
#
# Project created by QtCreator 2019-07-04T10:21:29
#
#-------------------------------------------------

QT       += core gui
QT += core gui widgets network serialport sql quickwidgets quick qml
QT += multimedia
QT += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = HPLC-MS
TEMPLATE = app

OBJECTS_DIR  = tmp
MOC_DIR      = tmp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    AddSampleWindow.cpp \
    CJsonObject.cpp \
    CheckAMSWindow.cpp \
    DataFitting.cpp \
    LockWaveWindow.cpp \
    MyCustomPlot.cpp \
    MyDoubleSpinBox.cpp \
    MyMainPushButton.cpp \
    MySpinBox.cpp \
    MyThread.cpp \
    QMessageSendAndRevice.cpp \
    SQLList.cpp \
    SampleInfoInsertWindow.cpp \
    ToggleWindow.cpp \
    WaveHistoryData.cpp \
    cJSON.c \
    clippipevalvewindow.cpp \
    connectMYSQL.cpp \
    controlpancelwindow.cpp \
    historydatatodisk.cpp \
    libinfowindow.cpp \
    librarywindow.cpp \
    loginwindow.cpp \
        main.cpp \
    crcCheckSum.cpp \
    GaugeRingBuffer.cpp \
    HPLCMS.cpp \
    InjectPumpRingbuffer.cpp \
    MyTracer.cpp \
    Protocol.cpp \
    RingBuffer.cpp \
    WaveFormWindow.cpp \
    ChromatographicFormWindow.cpp \
    MainWindow.cpp \
    MenuWindow.cpp \
    CameraWindow.cpp \
    permissionwindow.cpp \
    progressbarwindow.cpp \
    progresswindow.cpp \
    qcustomplot.cpp \
    qualitative_param_window.cpp \
    slidingwindow.cpp \
    systemcheckwindow.cpp \
    systemconfigurationwindow.cpp \
    tdesiringbuffer.cpp \
    wavepeaklistwindow.cpp

HEADERS += \
    AddSampleWindow.h \
    CJsonObject.hpp \
    CheckAMSWindow.h \
    DataFitting.h \
    LockWaveWindow.h \
    MyCustomPlot.h \
    MyDoubleSpinBox.h \
    MyMainPushButton.h \
    MySpinBox.h \
    MyThread.h \
    QMessageSendAndRevice.h \
    SQLList.h \
    SampleInfoInsertWindow.h \
    ToggleWindow.h \
    WaveHistoryData.h \
    cJSON.h \
    clippipevalvewindow.h \
    connectMYSQL.h \
    controlpancelwindow.h \
    crcCheckSum.h \
    GaugeRingBuffer.h \
    HPLCMS.h \
    InjectPumpRingbuffer.h \
    MyTracer.h \
    Protocol.h \
    ProtocolCodeList.h \
    historydatatodisk.h \
    libinfowindow.h \
    librarywindow.h \
    loginwindow.h \
    permissionwindow.h \
    progressbarwindow.h \
    progresswindow.h \
    qcustomplot.h \
    RingBuffer.h \
    WaveFormWindow.h \
    ChromatographicFormWindow.h \
    MainWindow.h \
    MenuWindow.h \
    CameraWindow.h \
    qualitative_param_window.h \
    slidingwindow.h \
    stdfix.h \
    systemcheckwindow.h \
    systemconfigurationwindow.h \
    tdesiringbuffer.h \
    wavepeaklistwindow.h

FORMS += \
    AddSampleWindow.ui \
    CheckAMSWindow.ui \
    HPLCMS.ui \
    LockWaveWindow.ui \
    SampleInfoInsertWindow.ui \
    ToggleWindow.ui \
    WaveFormWindow.ui \
    ChromatographicFormWindow.ui \
    MainWindow.ui \
    MenuWindow.ui \
    CameraWindow.ui \
    WaveHistoryData.ui \
    clippipevalvewindow.ui \
    controlpancelwindow.ui \
    libinfowindow.ui \
    librarywindow.ui \
    loginwindow.ui \
    permissionwindow.ui \
    progressbarwindow.ui \
    progresswindow.ui \
    qualitative_param_window.ui \
    slidingwindow.ui \
    systemcheckwindow.ui \
    systemconfigurationwindow.ui \
    wavepeaklistwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource/icon.qrc \
    resource/images.qrc \
    resource/qml.qrc \
    resource/qss.qrc
RC_FILE = icon.rc

DISTFILES += \
    mapper/datafit.json \
    mapper/qt_zh_CN.qm \
    mapper/sample.json
