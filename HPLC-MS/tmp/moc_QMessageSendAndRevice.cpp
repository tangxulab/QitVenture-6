/****************************************************************************
** Meta object code from reading C++ file 'QMessageSendAndRevice.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QMessageSendAndRevice.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QMessageSendAndRevice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QMessageSendAndRevice_t {
    QByteArrayData data[16];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMessageSendAndRevice_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMessageSendAndRevice_t qt_meta_stringdata_QMessageSendAndRevice = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QMessageSendAndRevice"
QT_MOC_LITERAL(1, 22, 11), // "startThread"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 10), // "threadStop"
QT_MOC_LITERAL(4, 46, 17), // "molecularPumpData"
QT_MOC_LITERAL(5, 64, 4), // "data"
QT_MOC_LITERAL(6, 69, 14), // "SerialPortData"
QT_MOC_LITERAL(7, 84, 4), // "type"
QT_MOC_LITERAL(8, 89, 7), // "GUIData"
QT_MOC_LITERAL(9, 97, 7), // "ESIData"
QT_MOC_LITERAL(10, 105, 9), // "injectata"
QT_MOC_LITERAL(11, 115, 15), // "injectataVolume"
QT_MOC_LITERAL(12, 131, 14), // "readData2vacrb"
QT_MOC_LITERAL(13, 146, 6), // "doWork"
QT_MOC_LITERAL(14, 153, 13), // "pushIntoQueue"
QT_MOC_LITERAL(15, 167, 5) // "array"

    },
    "QMessageSendAndRevice\0startThread\0\0"
    "threadStop\0molecularPumpData\0data\0"
    "SerialPortData\0type\0GUIData\0ESIData\0"
    "injectata\0injectataVolume\0readData2vacrb\0"
    "doWork\0pushIntoQueue\0array"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMessageSendAndRevice[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    2,   66,    2, 0x06 /* Public */,
       8,    2,   71,    2, 0x06 /* Public */,
       9,    2,   76,    2, 0x06 /* Public */,
      10,    2,   81,    2, 0x06 /* Public */,
      11,    2,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   91,    2, 0x0a /* Public */,
      13,    0,   92,    2, 0x0a /* Public */,
      14,    2,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 6,    5,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray, 0x80000000 | 6,   15,    7,

       0        // eod
};

void QMessageSendAndRevice::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QMessageSendAndRevice *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startThread(); break;
        case 1: _t->threadStop(); break;
        case 2: _t->molecularPumpData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        case 3: _t->GUIData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        case 4: _t->ESIData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        case 5: _t->injectata((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        case 6: _t->injectataVolume((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        case 7: _t->readData2vacrb(); break;
        case 8: _t->doWork(); break;
        case 9: _t->pushIntoQueue((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< SerialPortData(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QMessageSendAndRevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::startThread)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::threadStop)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)(QString , SerialPortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::molecularPumpData)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)(QString , SerialPortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::GUIData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)(QString , SerialPortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::ESIData)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)(QString , SerialPortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::injectata)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QMessageSendAndRevice::*)(QString , SerialPortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QMessageSendAndRevice::injectataVolume)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QMessageSendAndRevice::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QMessageSendAndRevice.data,
    qt_meta_data_QMessageSendAndRevice,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QMessageSendAndRevice::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMessageSendAndRevice::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QMessageSendAndRevice.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QMessageSendAndRevice::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QMessageSendAndRevice::startThread()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QMessageSendAndRevice::threadStop()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QMessageSendAndRevice::molecularPumpData(QString _t1, SerialPortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QMessageSendAndRevice::GUIData(QString _t1, SerialPortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QMessageSendAndRevice::ESIData(QString _t1, SerialPortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QMessageSendAndRevice::injectata(QString _t1, SerialPortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void QMessageSendAndRevice::injectataVolume(QString _t1, SerialPortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
