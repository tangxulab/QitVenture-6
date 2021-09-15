/****************************************************************************
** Meta object code from reading C++ file 'Protocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Protocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Protocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Protocol_t {
    QByteArrayData data[16];
    char stringdata0[213];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_t qt_meta_stringdata_Protocol = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Protocol"
QT_MOC_LITERAL(1, 9, 16), // "wave_data_change"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 43, 1), // "x"
QT_MOC_LITERAL(5, 45, 1), // "y"
QT_MOC_LITERAL(6, 47, 20), // "avg_wave_data_change"
QT_MOC_LITERAL(7, 68, 21), // "clip_pipe_data_change"
QT_MOC_LITERAL(8, 90, 9), // "mock_none"
QT_MOC_LITERAL(9, 100, 17), // "getPeakListSignal"
QT_MOC_LITERAL(10, 118, 16), // "sendNoTestSignal"
QT_MOC_LITERAL(11, 135, 13), // "QList<double>"
QT_MOC_LITERAL(12, 149, 12), // "noTestSignal"
QT_MOC_LITERAL(13, 162, 30), // "multiplier_tube_voltage_signal"
QT_MOC_LITERAL(14, 193, 9), // "ShowOneMS"
QT_MOC_LITERAL(15, 203, 9) // "ShowOneSS"

    },
    "Protocol\0wave_data_change\0\0QVector<double>\0"
    "x\0y\0avg_wave_data_change\0clip_pipe_data_change\0"
    "mock_none\0getPeakListSignal\0"
    "sendNoTestSignal\0QList<double>\0"
    "noTestSignal\0multiplier_tube_voltage_signal\0"
    "ShowOneMS\0ShowOneSS"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    0,   65,    2, 0x06 /* Public */,
       8,    0,   66,    2, 0x06 /* Public */,
       9,    0,   67,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,
      13,    4,   71,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    0,   80,    2, 0x0a /* Public */,
      15,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Double, QMetaType::QByteArray, QMetaType::QByteArray,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Protocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Protocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->wave_data_change((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2]))); break;
        case 1: _t->avg_wave_data_change(); break;
        case 2: _t->clip_pipe_data_change(); break;
        case 3: _t->mock_none(); break;
        case 4: _t->getPeakListSignal(); break;
        case 5: _t->sendNoTestSignal((*reinterpret_cast< QList<double>(*)>(_a[1]))); break;
        case 6: _t->multiplier_tube_voltage_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3])),(*reinterpret_cast< QByteArray(*)>(_a[4]))); break;
        case 7: _t->ShowOneMS(); break;
        case 8: _t->ShowOneSS(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Protocol::*)(QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::wave_data_change)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::avg_wave_data_change)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::clip_pipe_data_change)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::mock_none)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::getPeakListSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Protocol::*)(QList<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::sendNoTestSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Protocol::*)(int , double , QByteArray , QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::multiplier_tube_voltage_signal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Protocol::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Protocol.data,
    qt_meta_data_Protocol,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Protocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Protocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Protocol::wave_data_change(QVector<double> _t1, QVector<double> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Protocol::avg_wave_data_change()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Protocol::clip_pipe_data_change()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Protocol::mock_none()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Protocol::getPeakListSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Protocol::sendNoTestSignal(QList<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Protocol::multiplier_tube_voltage_signal(int _t1, double _t2, QByteArray _t3, QByteArray _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
